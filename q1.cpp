#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void BFS(int start, vector<vector<int>>& graph, int n) {
    vector<bool> visited(n, false); 
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Visit all neighbors
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int n = 6; 
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    BFS(0, graph, n);

    return 0;
}
