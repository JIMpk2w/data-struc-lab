#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;

    vector<int> degree(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    cout << degree[k] << endl;

    return 0;
}