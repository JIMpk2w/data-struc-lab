#include <iostream>

using namespace std;

void input_grid(int grid[][100], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
}

bool is_valid_path(int grid[][100], int x, int y, int n) {
    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 1) {
        return false;
    }
    if (x == n - 1 && y == n - 1) {
        return true;
    }
    
    grid[x][y] = 1;  // Mark the cell as visited
    
    bool result = false;
    result |= is_valid_path(grid, x - 1, y, n);  // Up
    result |= is_valid_path(grid, x + 1, y, n);  // Down
    result |= is_valid_path(grid, x, y - 1, n);  // Left
    result |= is_valid_path(grid, x, y + 1, n);  // Right
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    int grid[100][100];

    input_grid(grid, n);
    
    if (is_valid_path(grid, 0, 0, n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
