#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

void read_input(std::vector<std::tuple<int, int, int> > &graph, int &node_count) {
    std::ifstream f("input.txt");
    int edge_count;
    f >> node_count >> edge_count;

    for (int _ = 0; _ < edge_count; _++) {
        int u, v, w;
        f >> u >> v >> w;
        graph.emplace_back(u - 1, v - 1, w);
    }

    f.close();
}

int find(std::vector<int> &parent, const int node) {
    return (parent[node] == node) ? node : parent[node] = find(parent, parent[node]);
}

void unite(std::vector<int> &parent, std::vector<int> &rank, const int x, const int y) {
    const int p1 = find(parent, x);
    const int p2 = find(parent, y);

    if (p1 != p2) {
        if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else {
            parent[p1] = p2;
            ++rank[p2];
        }
    }
}

void kruskal(std::vector<std::tuple<int, int, int> > &graph, const int node_count) {
    std::ranges::sort(graph, [](const std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    std::vector<int> parent(node_count), rank(node_count);
    for (int i = 0; i < node_count; ++i) {
        parent[i] = i;
        rank[i] = i;
    }

    int mst_cost = 0;
    int count_edges = 0;
    for (const auto &[u, v, w]: graph) {
        if (find(parent, u) != find(parent, v)) {
            std::cout << "(" << u + 1 << "," << v + 1 << ") w=" << w << "\n";

            unite(parent, rank, u, v);
            mst_cost += w;

            if (++count_edges == node_count - 1) {
                std::cout << "Total cost: " << mst_cost;
                return;
            }
        }
    }
}

int main() {
    std::vector<std::tuple<int, int, int> > graph;
    int node_count;

    read_input(graph, node_count);
    kruskal(graph, node_count);
    return 0;
}
