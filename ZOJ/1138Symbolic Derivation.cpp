/**
 * P1012: Symbolic Derivation
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: Expression Recursion
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <string>
using namespace std;

// derive an expression
string derive(string exp) {
    // single x
    if (exp == "x") {
        return "1";
    }
    int op = -1;
    int level = 0;
    // locate global operator
    for (int i = 0, m = exp.length(); i < m; ++i) {
        char ch = exp[i];
        if (ch == '(') {
            ++level;
        } else if (ch == ')') {
            --level;
        } else if (level == 0) {
            if (ch == '+' || ch == '-') {
                if (i > 0) {
                    op = i;
                }
            } else if (ch == '*' || ch == '/') {
                if (op == -1 || exp[op] == '*' || exp[op] == '/') {
                    op = i;
                }
            }
        }
    }
    // no global operator present
    if (op == -1) {
        if (exp[0] == '(' && exp[exp.length() - 1] == ')') {
            // remove parenthesis
            return "(" + derive(exp.substr(1, exp.length() - 2)) + ")";
        } else if (exp[0] == 'l') {
            // ln() notation
            return derive(exp.substr(2)) + "/" + exp.substr(2); 
        } else {
            // constant
            return "0";
        }
    }
    string left = exp.substr(0, op), right = exp.substr(op + 1);
    string dleft = derive(left), dright = derive(right);
    // recursively solve derivation
    switch (exp[op]) {
    case '+':
        return dleft + "+" + dright;
    case '-':
        return dleft + "-" + dright;
    case '*':
        if (left[0] == '-') {
            return "(" + dleft + "*" + right + left + "*" + dright + ")";
        } else {
            return "(" + dleft + "*" + right + "+" + left + "*" + dright + ")";
        }
    case '/':
        if (left[0] == '-') {
            return "(" + dleft + "*" + right + "+" + left.substr(1) + "*" + dright + ")/" + right + "^2";
        } else {
            return "(" + dleft + "*" + right + "-" + left + "*" + dright + ")/" + right + "^2";
        }
    default:
        // never reach here
        return "N/A";
    }
}

bool run() {
    string exp;
    if (!(cin >> exp)) {
        return false;
    }
    cout << derive(exp) << endl;
    return true;
}

int main() {
    while (run());
    return 0;
}
