#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

class Solution {
public:
    string minWindow(string S, string T) {
        map<char, int> mp, tp;
        REP(i,T.length()) {
            if (mp.find(T[i]) == mp.end()) mp[T[i]] = 1;
            else ++mp[T[i]];
        }
        int cnt = 0, rt = -1;
        REP(i,S.length()) {
            char ch = S[i];
            if (mp.find(ch) == mp.end()) continue;
            if (tp.find(ch) == tp.end()) tp[ch] = 1;
            else ++tp[ch];
            if (tp[ch] == mp[ch]) {
                ++cnt;
                if (cnt == mp.size()) {
                    rt = i;
                    break;
                }
            }
        }
        if (rt == -1) return "";
        int lt = 0;
        string res = S.substr(0, rt + 1);
        while (true) {
            while (true) {
                if (mp.find(S[lt]) == mp.end()) {
                    ++lt;
                    continue;
                }
                if (tp[S[lt]] > mp[S[lt]]) {
                    --tp[S[lt]];
                    ++lt;
                    continue;
                }
                break;
            }
            if (rt + 1 - lt < res.length()) res = S.substr(lt, rt + 1 - lt);
            ++rt;
            if (rt >= S.length()) break;
            char ch = S[rt];
            if (mp.find(ch) == mp.end()) continue;
            ++tp[ch];
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << s.minWindow("ab", "b") << endl;
    return 0;
}
