#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PII; // (distance, vertex)

void dijkstra(int start, vector<vector<PII>>& graph, int n) {
    vector<int> dist(n, INT_MAX);   // Distance array
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start}); // (distance, node)

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entry

        for (auto [weight, v] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<PII>> graph(n);
    graph[0].push_back({10,1});
    graph[0].push_back({3,2});
    graph[1].push_back({10,0});
    graph[1].push_back({1,2});
    graph[1].push_back({2,3});
    graph[2].push_back({3,0});
    graph[2].push_back({1,1});
    graph[2].push_back({8,3});
    graph[2].push_back({2,4});
    graph[3].push_back({2,1});
    graph[3].push_back({8,2});
    graph[3].push_back({7,4});
    graph[4].push_back({2,2});
    graph[4].push_back({7,3});

    dijkstra(0, graph, n);

    return 0;
}