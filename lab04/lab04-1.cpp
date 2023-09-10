#include <iostream>
#include <stack>

using namespace std;

int main() {
    int num, command, push, count = 0;
    stack<int> stack;
    cin >> num;
    int stackOutput[num];
    
    while (num > 0) {
        cin >> command;
        if (command == 1) {
            cin >> push;
            stack.push(push);
        } else if (command == 2) {
            if (!stack.empty()) {
                stack.pop();
            }
        } else if (command == 3) {
            if (!stack.empty()) {
            stackOutput[count++] = stack.top();
            } else {
                cout << "EMPTY" << endl;
            }
        } else if (command == 4) {
            stackOutput[count++] = stack.size();
        }
        num--;
    }

    for (int i = 0; i < count; i++) {
       cout << stackOutput[i] << endl;
    }
    
}