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
#include <unordered_set>
#include <unordered_map>
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
    string sst;
    vector<VS> res;
    unordered_map<string, VS> mp;
    VS path;
    void output(string str) {
        path.PB(str);
        if (str == sst) {
            VS tt = path;
            reverse(tt.begin(), tt.end());
            res.PB(tt);
            path.pop_back();
            return;
        }
        REP(i,mp[str].size()) {
            output(mp[str][i]);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        sst = start;
        mp.clear();
        path.clear();
        res.clear();
        int len = start.length();
        VS que;
        que.push_back(start);
        int st = 0, ed = 0;
        while (st <= ed) {
            int num = ed + 1 - st;
            bool found = false;
            VS del;
            unordered_map<string, bool> dd;
            REP(ii,num) {
                string s = que[st + ii];
                string ss = s;
                if (dd.find(ss) != dd.end()) continue;
                dd[ss] = true;
                bool skip = false;
                REP(i,len) {
                    char bak = s[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        if (ch == s[i]) continue;
                        s[i] = ch;
                        if (s == end) {
                            mp[s].PB(ss);
                            found = true;
                            skip = true;
                            break;
                        }
                        if (dict.find(s) != dict.end()) {
                            mp[s].PB(ss);
                            que.PB(s);
                            del.PB(s);
                        }
                    }
                    if (skip) break;
                    s[i] = bak;
                }
            }
            if (found) {
                output(end);
                break;
            }
            REP(i,del.size()) dict.erase(del[i]);
            st += num;
            ed = que.size() - 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    unordered_set<string> dict;
    /*dict.insert("hot");
      dict.insert("dot");
      dict.insert("dog");
      dict.insert("lot");
      dict.insert("log");
      vector<VS> res = s.findLadders("hit", "cog", dict);*/
    dict.insert("aabaa");
    dict.insert("abbaa");
    dict.insert("baaaa");
    dict.insert("bbaaa");
    dict.insert("bbbaa");
    dict.insert("bbbac");
    vector<VS> res = s.findLadders("aaaaa", "bbbac", dict);
    REP(i,res.size()) {
        REP(j,res[i].size()) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
