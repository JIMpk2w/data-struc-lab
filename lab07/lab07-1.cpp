#include <iostream>
using namespace std;

int main() {
    int n, value, num, count = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[i] = num;
    }

    cin >> value;

    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    
    cout << count;
}