#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isTree(int N, int M, vector<vector<int>>& edges) {
    if (M != N - 1) {
        return false;  // The number of edges is not N-1, so it's not a tree.
    }

    vector<vector<int>> adjacency(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    queue<int> q;
    q.push(0);  // Start from the first node.

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;

        for (int neighbor : adjacency[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
            }
        }
    }

    for (bool v : visited) {
        if (!v) {
            return false;  // Not all nodes are reachable from the first node.
        }
    }

    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(M, vector<int>(2));

    for (int i = 0; i < M; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (isTree(N, M, edges)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
