#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;        
    cout << node << " ";           

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);  // Recursive call
        }
    }
}

int main() {
    int n = 6; // Number of vertices
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<bool> visited(n, false); // Track visited nodes

    cout << "DFS Traversal starting from node 0: ";
    DFS(0, graph, visited);

    return 0;
}