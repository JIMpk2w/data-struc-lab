#include <iostream>
#include <string>
#include <queue>

using namespace std;

void print_queue(queue<string>& q)
{
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}

bool isCatSound(const string &s) {
    int i = 0;
    bool foundM = false;
    bool foundE = false;
    bool foundO = false;
    bool foundW = false;

    for (char c : s) {
        if (c == 'm' || c == 'M') {
            if (foundE || foundO || foundW) {
                return false;
            }
            foundM = true;
        } else if ((c == 'e' || c == 'E') && foundM) {
            if (foundO || foundW) {
                return false;
            }
            foundE = true;
        } else if ((c == 'o' || c == 'O') && foundE) {
            if (foundW) {
                return false;
            }
            foundO = true;
        } else if ((c == 'w' || c == 'W') && foundO) {
            foundW = true;
        } else {
            return false;
        }
    }

    return foundM && foundE && foundO && foundW;
}

int main() {
    int count;
    cin >> count;
    queue<string> q;

    for (int i = 0; i < count; i++) {
        int countWord;
        string word;
        cin >> countWord >> word;

        if (isCatSound(word)) {
            q.push("YES");
        } else {
            q.push("NO");
        }
    }

    print_queue(q);

    return 0;
}
