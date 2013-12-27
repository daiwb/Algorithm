class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        if (numRows == 0) return ret;
        vector<int> m;
        m.push_back(1);
        ret.push_back(m);
        if (numRows == 1) return ret;
        for (int i = 2; i <= numRows; ++i) {
            m.clear();
            m.push_back(1);
            for (int j = 1; j < i - 1; ++j) m.push_back(ret[i - 2][j] + ret[i - 2][j - 1]);
            m.push_back(1);
            ret.push_back(m);
        }
        return ret;
    }
};