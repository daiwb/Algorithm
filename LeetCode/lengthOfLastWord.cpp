class Solution {
public:
    vector<string> split( const string& s, const string& delim =" " ) {
        vector<string> res;
        string t;
        for ( int i = 0 ; i != s.size() ; i++ ) {
            if ( delim.find( s[i] ) != string::npos ) {
                if ( !t.empty() ) {
                    res.push_back( t );
                    t = "";
                }
            } else {
                t += s[i];
            }
        }
        if ( !t.empty() ) {
            res.push_back(t);
        }
        return res;
    }
    int lengthOfLastWord(const char *s) {
        string str(s);
        vector<string> ret = split(str, " ");
        if (ret.empty()) return 0;
        return ret.back().length();
    }
};