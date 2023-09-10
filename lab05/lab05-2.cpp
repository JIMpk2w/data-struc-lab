#include <iostream>
#include <queue>

using namespace std;

int main() {
    int num, command, count = 0, value;
    queue<int> queue1;
    queue<string> queueOutput;
    cin >> num;
    
    while (num > 0) {
        cin >> command;
        if (command == 1) {
            cin >> value;
            queue1.push(value);
        } else if (command == 2) {
            if (!queue1.empty()) {
                queue1.pop();
            }
        } else if (command == 3) {
            if (!queue1.empty()) {
                queueOutput.push(to_string(queue1.front()));
            } else {
                queueOutput.push("EMPTY");
            }
        } else if (command == 4) {
            queueOutput.push(to_string(queue1.size()));
        }
        num--;
    }

    while(!queueOutput.empty()) {
        cout << queueOutput.front() << endl;
        queueOutput.pop();
    }
    
    return 0;
}
