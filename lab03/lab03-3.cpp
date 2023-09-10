#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string removeVowels(string input) {
    string ans;
    size_t length = input.length();
    size_t i = 0;

    while (i < length) {
        if (!isspace(input[i])) {
            ans += input[i];
            if (isVowel(input[i]) && i + 1 < length && !isspace(input[i + 1])) {
                i += 3;
            } else {
                i++;
            }
        } else {
            ans += input[i];
            i++;
        }
    }

    return ans;
}

int main() {
    string word;
    getline(cin, word);

    string converted = removeVowels(word);
    cout << converted << endl;

    return 0;
}