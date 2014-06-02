class Solution {
public:
    string s;
    vector<string> t;
    vector<vector<string> > res;
    bool isok(int st, int ed) {
        while (st < ed) {
            if (s[st] != s[ed]) return false;
            ++st;
            --ed;
        }
        return true;
    }
    void doit(int now) {
        if (now >= s.length()) {
            res.push_back(t);
            return;
        }
        
        for (int i = now; i < s.length(); ++i) {
            if (isok(now, i)) {
                t.push_back(s.substr(now, i - now + 1));
                doit(i + 1);
                t.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string _s) {
        s = _s;
        res.clear();
        t.clear();
        doit(0);
        return res;
    }
};