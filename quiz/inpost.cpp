#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

string infixToPostfix(const string& infixExpression) {
    string postfix;
    stack<char> operators;

    for (char c : infixExpression) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        } else if (isOperator(c)) {
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Infix: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
