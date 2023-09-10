#include <iostream>
#include <queue>

using namespace std;

int main() {
    int countPeople, valueMax, value;
    queue<int> queuePeople;
    queue<int> queueValue;
    queue<int> queueOutput;
    cin >> countPeople;
    cin >> valueMax;

    for (int i = 1; i <= countPeople; i++) {
        queuePeople.push(i);
        cin >> value;
        queueValue.push(value);
    }
    
    while (!queuePeople.empty()) {
        int balance = queueValue.front();

        if (balance - valueMax <= 0) {
            queueOutput.push(queuePeople.front());
            queuePeople.pop();
            queueValue.pop();
            continue;
        } else {
            queuePeople.push(queuePeople.front());
            queuePeople.pop();

            queueValue.push(queueValue.front() - valueMax);
            queueValue.pop();
        }
    }

    while(!queueOutput.empty()) {
        cout << queueOutput.front() << " ";
        queueOutput.pop();
    }
    
    return 0;
}