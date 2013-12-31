#define REP(i,n) for(int i=0;i<(n);++i)

class Solution {
public:
    string doit(vector<string>& mm, int L, bool last) {
        string res = "";
        int m = mm.size();
        int len = 0;
		REP(i,mm.size()) len += mm[i].length();
        
        if (m == 1 || last) {
            REP(i,mm.size()) res += mm[i];
			REP(i,L-len) res += " ";
            return res;
        }
        
        int left = L - len;
        int avg = left / (m - 1);
        int sz = left - avg * (m - 1);
        string sps = "";
        REP(i,avg) sps += " ";
        
        REP(i,mm.size()) {
			if (i > 0) {
				res += sps;
				if (i <= sz) res += " ";
			}
			res += mm[i];
        }
        return res;
    }
    
    vector<string> fullJustify(vector<string> &words, int L) {
        int n = words.size();
        int idx = 0;
        vector<string> ret;
        while (idx < n) {
            vector<string> mm;
            int len = words[idx].length();
            mm.push_back(words[idx++]);
            while (idx < n) {
                if (len + 1 + words[idx].length() <= L) {
                    len += 1 + words[idx].length();
                    mm.push_back(" " + words[idx++]);
                } else {
					break;
				}
            }
            bool last = (idx == n);
            ret.push_back(doit(mm, L, last));
        }
        return ret;
    }
};
