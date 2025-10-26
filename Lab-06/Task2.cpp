#include <iostream>
using namespace std;

class PostfixEvaluator {
    double stack[100];
    int topIndex;
public:
    PostfixEvaluator() {
        topIndex = -1;
    }
    bool empty() {
        return topIndex == -1;
    }
    void push(double value) {
        if (topIndex >= 99) {
            cout << "Stack overflow" << endl;
            return;
        }
        stack[++topIndex] = value;
    }
    double pop() {
        if (empty()) {
            cout << "Invalid expression" << endl;
            return 0;
        }
        return stack[topIndex--];
    }

    double top() {
        if (empty()) {
            cout << "Stack empty" << endl;
            return 0;
        }
        return stack[topIndex];
    }
    double evaluate(string exp) {
        for (int i = 0; i < exp.length(); i++) {
            char ch = exp[i];
            if (ch >= '0' && ch <= '9') {
                push(ch - '0');
            } else {
                double val2 = pop();
                double val1 = pop();
                switch (ch) {
                    case '+': push(val1 + val2); break;
                    case '-': push(val1 - val2); break;
                    case '*': push(val1 * val2); break;
                    case '/': 
                        if (val2 == 0) {
                            cout << "Division by zero" << endl;
                            return 0;
                        }
                        push(val1 / val2);
                        break;
                    default:
                        cout << "Invalid operator: " << ch << endl;
                        return 0;
                }
            }
        }
        if (topIndex != 0) {
            cout << "Invalid postfix expression" << endl;
            return 0;
        }
        return pop();
    }
};
int main() {
    PostfixEvaluator eval;
    string expression;
    cout << "Enter postfix expression (e.g., 23*54*+9-): ";
    cin >> expression;
    double result = eval.evaluate(expression);
    cout << "Result: " << result << endl;
    return 0;
}
