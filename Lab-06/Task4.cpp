#include <iostream>
using namespace std;

class InfixToPostfix {
    char stack[100];
    int topIndex;

public:
    InfixToPostfix() {
        topIndex = -1;
    }

    void push(char c) {
        if (topIndex >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++topIndex] = c;
    }

    char pop() {
        if (topIndex == -1) {
            return '\0';
        }
        return stack[topIndex--];
    }

    char top() {
        if (topIndex == -1)
            return '\0';
        return stack[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    }

    string convert(string infix) {
        string postfix = "";
        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                postfix += c;
            }
            else if (c == '(') {
                push(c);
            }
            else if (c == ')') {
                while (!isEmpty() && top() != '(') {
                    postfix += pop();
                }
                pop(); // remove '('
            }
            else if (isOperator(c)) {
                while (!isEmpty() && precedence(top()) >= precedence(c)) {
                    if (c == '^' && top() == '^') break; // right-associative
                    postfix += pop();
                }
                push(c);
            }
        }

        while (!isEmpty()) {
            postfix += pop();
        }

        return postfix;
    }
};

int main() {
    InfixToPostfix converter;
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string result = converter.convert(infix);
    cout << "Postfix expression: " << result << endl;
    return 0;
}
