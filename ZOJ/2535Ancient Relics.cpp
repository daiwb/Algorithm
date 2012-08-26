#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#define for if(0); else for

class line {
public:
    int visited[20];
}al[35];

string key[20];
int ks;
int n;

int keyw;
int ret;
vector<int> vv;
vector<int> ss;
vector<int> vvv;
vector<int> sss;

void dfs(int now, int len, int kw) {
    if (now == n) {
        if (kw == 0) return;
        if (kw > keyw) {
            keyw = kw;
            ret = len;
            vvv = vv;
            sss = ss;
        } else if (kw == keyw) {
            int flag = 0;
            for (int i = 0; i < ks; ++i) {
                if (vv[i] >= 1 && vvv[i] == 0) {
                    flag = 1;
                    break;
                } else if (vv[i] == 0 && vvv[i] >= 1) {
                    flag = -1;
                    break;
                }
            }
            if (flag == 1) {
                ret = len;
                vvv = vv;
                sss = ss;
            } else if (flag == 0) {
                if (len < ret) {
                    ret = len;
                    vvv = vv;
                    sss = ss;
                } else if (len == ret) {
                    int flag = 0;
                    for (int i = 0; i < len; ++i) {
                        if (ss[i] < sss[i]) {
                            flag = 1;
                            break;
                        } else if (ss[i] > sss[i]) {
                            flag = -1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        vvv = vv;
                        sss = ss;
                    }
                }
            }
        }
        return;
    }
    int flag = 0;
    int kkw = kw;
    for (int i = 0; i < ks; ++i) {
        if (al[now].visited[i]) {
            vv[i] += 1;
            if (vv[i] == 1) {
                flag = 1;
                ++kkw;
            }
        }
    }
    ss.push_back(now);
    if (flag) {
        dfs(now + 1, len + 1, kkw);
    }
    for (int i = 0; i < ks; ++i) {
        if (al[now].visited[i]) {
            vv[i] -= 1;
        }
    }
    ss.pop_back();
    dfs(now + 1, len, kw);
}

void run() {
    cin >> n >> ws;
    vvv.clear();
    sss.clear();
    ss.clear();
    vv.clear();
    ret = 100000;
    keyw = 0;
    ks = 0;
    string str;
    getline(cin, str);
    istringstream is(str);
    string s;
    while (is >> s) {
        key[ks++] = s;
    }
    for (int i = 1; i < n; ++i) {
        memset(al[i].visited, 0, sizeof(al[i].visited));
        getline(cin, str);
        istringstream is(str);
        string s;
        while (is >> s) {
            for (int j = 0; j < ks; ++j) {
                if (key[j] == s) {
                    al[i].visited[j] = 1;
                }
            }
        }
    }
    vv.assign(ks, 0);
    dfs(1, 0, 0);
    if (keyw == 0) {
        cout << "No keyword is found!" << endl;
        return;
    }
    int flag = 1;
    for (int i = 0; i < ks; ++i) {
        if (vvv[i]) {
            if (flag) flag = 0;
            else cout << " ";
            cout << key[i];
        }
    }
    cout << endl;
    sort(sss.begin(), sss.end());
    for (int i = 0; i < sss.size(); ++i) {
        if (i) cout << " ";
        cout << sss[i] - 1;
    }
    cout << endl;
}

int main() {
    int kase;
    cin >> kase;
    for (int kk = 0; kk < kase; ++kk) {
        if (kk) cout << endl;
        cout << "Case " << kk + 1 << ":" << endl;
        run();
    }
    return 0;
}
