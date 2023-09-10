#include <iostream>
#include <string>
#define MAX 1001
using namespace std;

int main() {
    char check[MAX];
    int ParenthesesOpen = 0, ParenthesesClose = 0, ParenthesesCloseCheck = 0;

    cin.getline(check, sizeof(check));

    for (int i = 0; check[i] != '\0'; i++) {
        if (check[i] == '(') { 
            ParenthesesOpen++;

            for (int l = i; l <= sizeof(check); l++) {
                if (check[l] == ')') {
                    ParenthesesClose++;
                    break;
                    }
            }
        }

        if (check[i] == ')') { ParenthesesCloseCheck++; }
    }

    if (ParenthesesOpen == ParenthesesCloseCheck && ParenthesesCloseCheck == ParenthesesClose) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
