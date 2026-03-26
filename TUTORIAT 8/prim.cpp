#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void read_graph(std::vector<std::vector<std::pair<int, int> > > &graph, int& n, const std::string &file_name) {
    std::ifstream f(file_name);

    int m;
    int u, v, w;
    f >> n >> m;
    graph.resize(n);
    while (m--) {
        f >> u >> v >> w;
        graph[u - 1].emplace_back(v - 1, w);
        graph[v - 1].emplace_back(u - 1, w);
    }

    f.close();
}

int prim(std::vector<std::vector<std::pair<int, int> > > &graph, const int n) {
    std::vector visited(n, false);
    std::priority_queue<std::pair<int, int>> pq; // this is a max-heap
    int cost = 0;

    pq.emplace(0, 0);
    while (!pq.empty()) {
        const int weight = -pq.top().first;
        const int node = pq.top().second;
        pq.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        cost += weight;

        for (const auto& [neighbour, w] : graph[node]) {
            if (!visited[neighbour]) {
                pq.emplace(-w, neighbour);
            }
        }
    }
    return cost;
}

int main() {
    std::vector<std::vector<std::pair<int, int> > > graph;
    int n;
    read_graph(graph, n, "input.in");

    std::cout<<prim(graph, n);
    return 0;
}
