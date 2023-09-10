#include <iostream>
#include <vector>

using namespace std;

vector<int> childrenCount;
vector<vector<int>> adj;

void dfs(int node) {
    childrenCount[node] = 0;
    for (int child : adj[node]) {
        dfs(child);
        childrenCount[node] += childrenCount[child] + 1;
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n + 1);
    childrenCount.resize(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << childrenCount[i] << " ";
    }

    return 0;
}
