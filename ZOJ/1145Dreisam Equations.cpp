/**
 * P1014: Dreisam Equations
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: DFS
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

// token type
enum type_t {
    pleft,
    pright,
    number
};

// token info
class token {
public:
    type_t type;
    int number;
    token(type_t type) : type(type) {
    }
    token(type_t type, int number) : type(type), number(number) {
    }
    string tostr() {
        ostringstream os;
        if (type == pleft) {
            os << '(';
        } else if (type == pright) {
            os << ')';
        } else {
            os << number;
        }
        return os.str();
    }
};

// parse the string into target number and token vector
bool parsetokens(string& exp, int& target, vector<token>& tokens) {
    istringstream is(exp);
    char ch;
    if (!(is >> target >> ch)) {
        return false;
    }
    while (is >> ch) {
        if (ch == '(') {
            tokens.push_back(token(pleft));
        } else if (ch == ')') {
            tokens.push_back(token(pright));
        } else {
            is.putback(ch);
            int num;
            is >> num;
            tokens.push_back(token(number, num));
        }
    }
    return true;
}

// remove the last item from the token sequence
vector<token> removelast(vector<token>& tokens) {
    vector<token> ret;
    // if the last token is a number, remove it
    if (tokens.back().type == number) {
        ret.push_back(tokens.back());
        tokens.pop_back();
    } else {
        // otherwise remove a pair of parentheses
        int level = 1;
        for (int i = tokens.size() - 2; i > 0; --i) {
            if (tokens[i].type == pleft) {
                --level;
                if (level == 0) {
                    ret.assign(tokens.begin() + i, tokens.end());
                    tokens.erase(tokens.begin() + i, tokens.end());
                    break;
                }
            } else if (tokens[i].type == pright) {
                ++level;
            }
        }
    }
    return ret;
}

// search all the target the token sequence can reach
map<int, string> equation(vector<token> tokens) {
    map<int, string> ret;
    if (tokens.size() == 1) {
        // only one number, return itself
        ret[tokens.back().number] = tokens.back().tostr();
    } else {
        vector<token> last = removelast(tokens);
        if (last.empty()) {
            // only one item, there is a wrapping parenthesis
            tokens.pop_back();
            tokens.erase(tokens.begin());
            ret = equation(tokens);
            for (map<int, string>::iterator itr = ret.begin(); itr != ret.end(); ++itr) {
                itr->second = "(" + itr->second + ")";
            }
        } else {
            // two parts
            map<int, string> tmp1 = equation(tokens), tmp2 = equation(last);
            for (map<int, string>::iterator itr1 = tmp1.begin(); itr1 != tmp1.end(); ++itr1) {
                for (map<int, string>::iterator itr2 = tmp2.begin(); itr2 != tmp2.end(); ++itr2) {
                    int n1 = itr1->first, n2 = itr2->first;
                    string s1 = itr1->second, s2 = itr2->second;
                    ret[n1 + n2] = s1 + "+" + s2;
                    ret[n1 - n2] = s1 + "-" + s2;
                    ret[n1 * n2] = s1 + "*" + s2;
                }
            }
        }
    }
    return ret;
}

bool run(int now) {
    string exp;
    getline(cin, exp);
    vector<token> tokens;
    int target;
    if (!parsetokens(exp, target, tokens)) {
        return false;
    }
    map<int, string> ret = equation(tokens);
    cout << "Equation #" << now << ':' << endl;
    if (ret.find(target) != ret.end()) {
        cout << target << '=' << ret[target] << endl << endl;
    } else {
        cout << "Impossible" << endl << endl;
    }
    return true;
}

int main() {
    int now = 0;
    while (run(++now));
    return 0;
}
