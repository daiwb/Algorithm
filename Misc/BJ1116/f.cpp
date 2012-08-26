#pragma warning(disable:4786)

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

#define for if(0); else for

vector<string> split( const string& s, const string& delim =",:" ) {
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

int n, m;
int num;
int start;
int ret;

int visited[2000];
map<string, int> mm;
map<string, int>::iterator it;
map<int, vector<int> > dd;

int dfs(int now) {
    map<int, vector<int> >::iterator itt;
    itt = dd.find(now);
    if (itt == dd.end()) {
        if (visited[now]) return 1;
        else return 0;
    }
    visited[now] = 2;
    vector<int> aa = dd[now];
    for (int i = 0; i < aa.size(); ++i) {
        int a = aa[i];
        if (visited[a] == 1) continue;
        if (visited[a] == 2) return 0;
        int s = dfs(a);
        if (s == 0) return 0;
        visited[a] = 1;
    }
    ++ret;
    visited[now] = 1;
    return 1;
}

void run() {
    memset(visited, 0, sizeof(visited));
    mm.clear();
    dd.clear();
    string str;
    getline(cin, str);
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        mm[str] = i;
        visited[i] = 1;
    }
    num = n;
    for (int i = 0; i < m; ++i) {
        string str;
        getline(cin, str);
        vector<string> temp = split(str);
        for (int j = 0; j < temp.size(); ++j) {
            if (temp[j][0] == ' ') {
                temp[j] = temp[j].substr(1);
            }
            if (temp[j][temp[j].length() - 1] == ' ') {
                temp[j] = temp[j].substr(0, temp[j].length() - 1);
            }
        }
        vector<int> ss;
        for (int j = 0; j < temp.size(); ++j) {
            it = mm.find(temp[j]);
            if (it == mm.end()) {
                mm[temp[j]] = num++;
            }
            ss.push_back(mm[temp[j]]);
        }
        ss.pop_back();
        dd[mm[temp[temp.size() - 1]]] = ss;
    }
    it = mm.find("Sorcerer's Stone");
    if (it == mm.end()) {
        cout << -1 << endl;
        return;
    } else {
        start = it->second;
    }
    //start = mm["Sorcerer's Stone"];
    if (visited[start]) {
        cout << 0 << endl;
        return;
    }
    ret = 0;

    /*
    vector<int> adai;
    adai.push_back(start);
    visited[start] = 2;
    int flag = 1;
    while (1) {
        if (adai.empty()) break;
        int now = adai[adai.size() - 1];
        visited[now] = 1;
        adai.pop_back();
        ++ret;
        map<int, vector<int> >::iterator itt;
        vector<int> nn = dd[now];
        for (int i = 0; i < nn.size(); ++i) {
            int aa = nn[i];
            itt = dd.find(aa);
            if (itt == dd.end()) {
                if (visited[aa] == 0) {
                    flag = 0;
                    break;
                }
            } else {
                if (visited[aa] == 1) continue;
                else if (visited[aa] == 2) {
                    flag = 0;
                    break;
                } else {
                    visited[aa] = 2;
                    adai.push_back(aa);
                }
            }
        }
        if (flag == 0) break;
    }
    */
    int rr = dfs(start);
    if (rr == 0) {
        cout << -1 << endl;
    } else {
        cout << ret << endl;
    }
}

int main() {
    while (cin >> n >> m && n + m) {
        run();
    }
    return 0;
}