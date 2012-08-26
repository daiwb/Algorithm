/**
 * P1008: Mondriaan's Dream
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: Combinatorics
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// pre-calculate all answers of width * 1 .. 11
void calc(vector<vector<double> >& ret, int width) {
    int scale = 1 << width;
    vector<double> cnt(scale, 0), tmp(scale);
    cnt[0] = 1;
    for (int level = 1; level <= 11; ++level) {
        copy(cnt.begin(), cnt.end(), tmp.begin());
        for (int i = 0; i < scale; ++i) {
            if (cnt[i] > 0) {
                // a stack of base code & starting position pairs
                vector<pair<int, int> > stack;
                stack.push_back(make_pair(i, 0));
                while (!stack.empty()) {
                    int base = stack.back().first;
                    int pos = stack.back().second;
                    // recursively count all possible horizontal dominos
                    // at position pos & pos + 1 (its mask is 3 << pos)
                    for (stack.pop_back(); pos < width - 1; ++pos) {
                        if ((base & (3 << pos)) == 0) {
                            tmp[base | (3 << pos)] += cnt[i];
                            stack.push_back(make_pair(base | (3 << pos), pos + 2));
                        }
                    }
                }
            }
        }
        // reverse copy the array to place vertical dominos
        copy(tmp.begin(), tmp.end(), cnt.rbegin());
        ret[width][level] = ret[level][width] = cnt[0];
    }
}

int main() {
    vector<vector<double> > ret(12, vector<double>(12, 0));
    for (int i = 2; i <= 10; i += 2) {
        calc(ret, i);
    }
    for (;;) {
        int m, n;
        cin >> m >> n;
        if (m == 0 && n == 0) {
            break;
        }
        printf("%.0lf\n", ret[m][n]);
    }
    return 0;
}
