// ac

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split( const string& s, const string& delim ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ) {
        vector<string> res;
        string t;
        for ( int i = 0 ; i != s.size() ; i++ ) {
                if ( delim.find( s[i] ) == string::npos ) {
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

void proc(string& s) {
        int len = s.length();
        for (int i = 0; i < len; ++i) {
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 'a' - 'A';
        }
}

int n, m;
vector<vector<string> > text;

void output(vector<pair<int, int> > out) {
        if (out.empty()) {
                cout << "Sorry, I found nothing." << endl;
                cout << "==========" << endl;
                return;
        }
        sort(out.begin(), out.end());
        int now = -1, first = 1;
        for (int i = 0; i < out.size(); ++i) {
                if (out[i].first != now) {
                        if (first) first = 0;
                        else cout << "----------" << endl;
                        now = out[i].first;
                }
                cout << text[out[i].first][out[i].second] << endl;
        }
        cout << "==========" << endl;
}

void run() {
        text.resize(n);
        map<string, set<pair<int, int> > > mm;
        string str;
        getline(cin, str);
        int pNo = 0;
        while (1) {
                int lNo = 0;
                while (1) {
                        getline(cin, str);
                        if (str == "**********") {
                                break;
                        }
                        text[pNo].push_back(str);
                        vector<string> tmp = split(str);
                        for (int i = 0; i < tmp.size(); ++i) {
                                proc(tmp[i]);
                                mm[tmp[i]].insert(make_pair(pNo, lNo));
                        }
                        ++lNo;
                }
                ++pNo;
                if (pNo == n) break;
        }
        for (cin >> m, getline(cin, str); m; --m) {
                getline(cin, str);
                istringstream is(str);
                string a, op, b;
                is >> a >> op >> b;
                proc(a), proc(op), proc(b);
                if (a == "not") {
                        set<pair<int, int> > dd = mm[op];
                        map<int, int> tt;
                        for (int i = 0; i < n; ++i) tt[i] = 0;
                        set<pair<int, int> >::iterator it;
                        for (it = dd.begin(); it != dd.end(); ++it) {
                                tt[it->first] = 1;
                        }
                        int flag = 1, first = 1;
                        for (int i = 0; i < n; ++i) {
                                if (tt[i] == 0) {
                                        flag = 0;
                                        if (first) first = 0;
                                        else cout << "----------" << endl;
                                        int size = text[i].size();
                                        for (int j = 0; j < size; ++j) {
                                                cout << text[i][j] << endl;
                                        }
                                }
                        }
                        if (flag) cout << "Sorry, I found nothing." << endl;
                        cout << "==========" << endl;
                } else if (op == "and") {
                        set<pair<int, int> > oo;
                        vector<pair<int, int> > out;
                        set<pair<int, int> > dda = mm[a];
                        set<pair<int, int> > ddb = mm[b];
                        map<int, int> tt1, tt2, tt;
                        for (int i = 0; i < n; ++i) {
                                tt1[i] = 0, tt2[i] = 0, tt[i] = 0;
                        }
                        set<pair<int, int> >::iterator it;
                        for (it = dda.begin(); it != dda.end(); ++it) {
                                tt1[it->first] = 1;
                        }
                        for (it = ddb.begin(); it != ddb.end(); ++it) {
                                tt2[it->first] = 1;
                        }
                        for (int i = 0; i < n; ++i) {
                                if (tt1[i] && tt2[i]) tt[i] = 1;
                        }
                        for (it = dda.begin(); it != dda.end(); ++it) {
                                if (tt[it->first]) oo.insert(*it);
                        }
                        for (it = ddb.begin(); it != ddb.end(); ++it) {
                                if (tt[it->first]) oo.insert(*it);
                        }
                        for (it = oo.begin(); it != oo.end(); ++it) {
                                out.push_back(*it);
                        }
                        output(out);
                } else if (op == "or") {
                        set<pair<int, int> > oo;
                        vector<pair<int, int> > out;
                        set<pair<int, int> > dd = mm[a];
                        set<pair<int, int> >::iterator it;
                        for (it = dd.begin(); it != dd.end(); ++it) {
                                oo.insert(*it);
                        }
                        dd = mm[b];
                        for (it = dd.begin(); it != dd.end(); ++it) {
                                oo.insert(*it);
                        }
                        for (it = oo.begin(); it != oo.end(); ++it) {
                                out.push_back(*it);
                        }
                        output(out);
                } else {
                        set<pair<int, int> > dd = mm[a];
                        vector<pair<int, int> > out;
                        set<pair<int, int> >::iterator it;
                        for (it = dd.begin(); it != dd.end(); ++it) {
                                out.push_back(*it);
                        }
                        output(out);
                }
        }
}

int main() {
        while (cin >> n) {
                run();
        }
        return 0;
}
