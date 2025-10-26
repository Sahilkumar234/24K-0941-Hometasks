#include <iostream>
#include <cmath>
using namespace std;

class PrefixEvaluator {
    double stack[100];
    int topIndex;

public:
    PrefixEvaluator() {
        topIndex = -1;
    }

    void push(double value) {
        if (topIndex >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++topIndex] = value;
    }

    double pop() {
        if (topIndex == -1) {
            cout << "Invalid expression" << endl;
            return 0;
        }
        return stack[topIndex--];
    }
    bool empty() {
        return topIndex == -1;
    }
    double evaluate(string exp) {
        for (int i = exp.length() - 1; i >= 0; i--) {
            char ch = exp[i];
            if (ch >= '0' && ch <= '9') {
                push(ch - '0');
            } 
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
                double op1 = pop();
                double op2 = pop();
                double result = 0;

                switch (ch) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': 
                        if (op2 == 0) {
                            cout << "Division by zero error" << endl;
                            return 0;
                        }
                        result = op1 / op2; 
                        break;
                    case '^': result = pow(op1, op2); break;
                }
                push(result);
            }
        }
        if (topIndex != 0) {
            cout << "Invalid prefix expression" << endl;
            return 0;
        }

        return pop();
    }
};

int main() {
    PrefixEvaluator evaluator;
    string expression;

    cout << "Enter prefix expression: ";
    cin >> expression;

    double result = evaluator.evaluate(expression);
    cout << "Result: " << result << endl;
    return 0;
}
