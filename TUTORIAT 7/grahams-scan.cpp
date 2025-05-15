#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <iomanip>

std::pair<double, double> base_point;

void read_input(std::vector<std::pair<double, double> > &points, int &n) {
    std::ifstream f("infasuratoare.in");
    f >> n;
    for (int _ = 0; _ < n; ++_) {
        double x, y;
        f >> x >> y;
        points.emplace_back(x, y);
    }
    f.close();
}

std::pair<double, double> before_top(std::stack<std::pair<double, double> > &s) {
    const std::pair<double, double> top = s.top();
    s.pop();

    const std::pair<double, double> before_top = s.top();
    s.push(top);

    return before_top;
}

int orientation(const std::pair<double, double> &a, const std::pair<double, double> &b,
                const std::pair<double, double> &c) {
    const double val = (b.second - a.second) * (c.first - a.first) - (c.second - a.second) * (b.first - a.first);

    if (val < 0) {
        return 1; // counter-clockwise
    }

    if (val > 0) {
        return 2; // clockwise
    }

    return 0; // collinear
}

double squared_distance(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    return (b.second - a.second) * (b.second - a.second) + (b.first - a.first) * (b.first - a.first);
}

bool comp(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    const int o = orientation(base_point, a, b);

    if (o == 0) {
        return squared_distance(base_point, a) < squared_distance(base_point, b);
    }

    return o == 1;
}

void grahams_scan(std::vector<std::pair<double, double> > &points, const int n) {
    if (n < 3) {
        return;
    }

    int lowest_point = 0;
    for (int i = 1; i < n; ++i) {
        if (points[i].second < points[lowest_point].second) {
            lowest_point = i;
        } else if (points[i].second == points[lowest_point].second && points[i].first < points[lowest_point].first) {
            lowest_point = i;
        }
    }

    std::swap(points[0], points[lowest_point]);
    base_point = points[0];
    std::sort(points.begin() + 1, points.end(), comp);

    std::stack<std::pair<double, double> > s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);

    for (int i = 3; i < n; ++i) {
        while (s.size() > 1 && orientation(before_top(s), s.top(), points[i]) != 1) {
            s.pop();
        }
        s.push(points[i]);
    }

    std::vector<std::pair<double, double> > hull;
    while (!s.empty()) {
        hull.push_back(s.top());
        s.pop();
    }

    std::ofstream g("infasuratoare.out");
    g << hull.size() << "\n" << std::fixed << std::setprecision(6);

    std::ranges::reverse(hull);
    for (const auto &[x, y]: hull) {
        g << x << " " << y << "\n";
    }

    g.close();
}

int main() {
    int n;
    std::vector<std::pair<double, double> > points;

    read_input(points, n);
    grahams_scan(points, n);
    return 0;
}
