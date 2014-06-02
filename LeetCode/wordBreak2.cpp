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
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        VS res;
        int len = s.length();
        if (len == 0) return res;
        vector<VI> valid(len, VI(len, 0));
        REP(i,len) {
            FOR(j,i,len-1) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) valid[i][j] = 1;
            }
        }
        vector<VS> mm(len);
        RFOR(i,len-1,0) {
            if (valid[i][len - 1]) mm[i].PB(s.substr(i));
            FOR(j,i,len-2) {
                if (!valid[i][j]) continue;
                string now = s.substr(i, j - i + 1);
                REP(k,mm[j+1].size()) {
                    mm[i].PB(now + " " + mm[j + 1][k]);
                }
            }
        }
        return mm[0];
    }
};