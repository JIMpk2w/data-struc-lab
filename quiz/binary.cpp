#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(const int arr[], int left, int right, int target, int &searchCount, int size) {
    while (searchCount < size / 3) {
        int mid = (right + left) / 2;
        searchCount++;
        
        if (arr[mid-1] == target)
            return mid;

        if (arr[mid-1] < target)
            left = mid;
        else
            right = mid;
    }
    return -1;
}

int main() {
    int data[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
    int size = sizeof(data) / sizeof(data[0]);
    
    cout << "Original data: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    sort(data, data + size);

    cout << "Sorted data: ";
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    int target1 = 5;
    int target2 = 90;
    int searchCount1 = 0;
    int searchCount2 = 0;

    int position1 = binarySearch(data, 1, size, target1, searchCount1, size);
    int position2 = binarySearch(data, 1, size, target2, searchCount2, size);

    if (position1 != -1) {
        cout << "Found " << target1 << " at position " << position1 << " or index " << position1 - 1 << " with " << searchCount1 << " comparisons." << endl;
    } else {
        cout << target1 << " not found." << endl;
    }

    if (position2 != -1) {
        cout << "Found " << target2 << " at position " << position2 << " or index " << position2 - 1 << " with " << searchCount2 << " comparisons." << endl;
    } else {
        cout << target2 << " not found." << endl;
    }

    return 0;
}
