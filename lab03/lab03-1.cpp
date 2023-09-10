#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i < rows; i++) {
        vector<int> temp(cols);

        for (int j = 0; j < cols; j++) {
            int prev = matrix[i - 1][j];
            temp[j] = matrix[i][prev - 1];
        }

        matrix[i] = temp;
    }

    for (int i = 0; i < cols; i++) {
        cout << matrix[rows - 1][i] << " ";
    }

    return 0;
}