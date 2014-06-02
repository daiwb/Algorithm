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
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) return 0;
        dict.erase(start);
        int len = start.length();
        deque<pair<string, int> > que;
        que.push_back(make_pair(start, 1));
        while (!que.empty()) {
            pair<string, int> item = que.front();
            que.pop_front();
            string s = item.first;
            int c = item.second;
            REP(i,len) {
                char bak = s[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    s[i] = ch;
                    if (s == end) return c + 1;
                    if (dict.find(s) != dict.end()) {
                        que.push_back(make_pair(s, c + 1));
                        dict.erase(s);
                    }
                }
                s[i] = bak;
            }
        }
        return 0;
    }
};