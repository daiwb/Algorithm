class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) return false;
        int len = s.length();
        vector<vector<bool> > mm(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) mm[i][j] = true;
            }
        }
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                for (int k = i; k < j; ++k) {
                    if (mm[i][k] && mm[k + 1][j]) mm[i][j] = true;
                }
            }
        }
        return mm[0][len - 1];
    }
};