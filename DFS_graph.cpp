#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited) {
    cout << node << " ";
    visited[node] = true;
    for (auto i : adj[node]) {
        if (visited[i] == false) {
            dfs(i, adj, visited);
        }
    }
}

void DFS(int v, int e, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < e; i++) {
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            dfs(i, adj, visited);
        }
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << "DFS Traversal: ";
    DFS(v, e, edges);

    return 0;
}
