/**
 * ZOJ 1136 Multiple
 *
 * 2005/05/27 By adai
 *
 * Algo Desc: BFS
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class node {
public:
    string str;
    int res;
    node &operator = (const node &cc){
        str = cc.str;
        res = cc.res;
        return *this;
	}
};

string alpha[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
int n;

int bfs(vector<node>& queue, int num, vector<int>& digi, vector<int>& res) {
    int head, tail, nhead, ntail;
    head = 0, tail = num - 1;
    while (1) {
        nhead = tail + 1, ntail = tail;
        for (int i = head; i <= tail; ++i) {
            for (int j = 0; j < digi.size(); ++j) {
                node temp;
                temp.str = queue[i].str + alpha[digi[j]];
                temp.res = (10 * queue[i].res + digi[j]) % n;
                if (temp.res == 0) {
                    cout << temp.str << endl;
                    return 1;
                }
                if (res[temp.res] == 0) {
                    res[temp.res] = 1;
                    queue[++ntail] = temp;
                }
            }
        }
        if (ntail < nhead) break;
        for (int i = nhead; i <= ntail; ++i) queue[i - nhead] = queue[i];
        head = 0, tail = ntail - nhead;
    }
    return 0;
}

void Run() {
    vector<int> digi;
    int m, in;
    for (cin >> m; m; --m) {
        cin >> in;
        digi.push_back(in);
    }
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    sort(digi.begin(), digi.end());
    vector<int> res(n, 0);
    vector<node> queue(10000);
    int num = 0;
    for (int i = 0; i < digi.size(); ++i) {
        if (digi[i] == 0) continue;
        if (res[digi[i] % n]) continue;
        else {
            if (digi[i] % n == 0) {
                cout << digi[i] << endl;
                return;
            }
            res[digi[i] % n] = 1;
            node temp;
            temp.str = alpha[digi[i]];
            temp.res = digi[i] % n;
            queue[num++] = temp;
        }
    }
    if (bfs(queue, num, digi, res) == 0) {
        cout << 0 << endl;
    }
}

int main() {
    while (cin >> n) {
        Run();
    }
    return 0;
}
