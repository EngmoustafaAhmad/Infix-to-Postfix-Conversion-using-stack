#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int periority(char c) {
    if (c == '-' || c == '+') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '^') return 3;
    return 0;
}

string infix_to_postfix(string exp) {
    stack<char> stk;
    string output = "";

    for (int i = 0; i < exp.length(); i++) {

        if (exp[i] == ' ') continue;

        // Operand
        if (isdigit(exp[i]) || isalpha(exp[i])) {
            output += exp[i];
        }

        // Opening bracket
        else if (exp[i] == '(') {
            stk.push('(');
        }

        // Closing bracket
        else if (exp[i] == ')') {
            while (!stk.empty() && stk.top() != '(') {
                output += stk.top();
                stk.pop();
            }
            stk.pop(); // remove '('
        }

        // Operator
        else {
            while (!stk.empty() && periority(exp[i]) <= periority(stk.top())) {
                output += stk.top();
                stk.pop();
            }
            stk.push(exp[i]);
        }
    }

    // Pop remaining operators
    while (!stk.empty()) {
        output += stk.top();
        stk.pop();
    }

    return output;
}

int main() {
    string infixExpression = "(3+2)+7/2*((7+3)*2)";
    cout << infix_to_postfix(infixExpression) << endl;
    return 0;
}
