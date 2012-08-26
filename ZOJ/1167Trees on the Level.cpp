/**
 * ZOJ 1167 Trees on the Level
 *
 * 2005/05/28 By adai
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class node {
public:
    int value;
    int left;
    int right;
    node(int value) {
        this->value = value;
        left = right = -1;
    }
};

string in;
bool complete;

void print(vector<node>& tree) {
    if (!complete) {
        cout << "not complete" << endl;
        return;
    }
    vector<int> out;
    vector<int> queue(10000);
    queue[0] = 0;
    int head, tail, nhead, ntail;
    head = tail = 0;
    while (1) {
        nhead = tail + 1, ntail = tail;
        for (int i = head; i <= tail; ++i) {
            if (tree[queue[i]].value == -1) {
                cout << "not complete" << endl;
                return;
            }
            out.push_back(tree[queue[i]].value);
            if (tree[queue[i]].left != -1) queue[++ntail] = tree[queue[i]].left;
            if (tree[queue[i]].right != -1) queue[++ntail] = tree[queue[i]].right;
        }
        if (ntail < nhead) break;
        for (int i = nhead; i <= ntail; ++i) queue[i - nhead] = queue[i];
        head = 0, tail = ntail - nhead;
    }
    for (int i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << endl;
}

void Run() {
    complete = true;
    vector<node> tree;
    tree.push_back(node(-1));
    while (1) {
        int value = 0, i;
        for (i = 1; in[i] != ','; ++i) value = value * 10 + in[i] - '0';
        int now = 0;
        for (++i; i < in.size() - 1; ++i) {
            if (in[i] == 'L') {
                if (tree[now].left == -1) {
                    tree.push_back(node(-1));
                    tree[now].left = tree.size() - 1;
                }
                now = tree[now].left;
            } else {
                if (tree[now].right == -1) {
                    tree.push_back(node(-1));
                    tree[now].right = tree.size() - 1;
                }
                now = tree[now].right;
            }
        }
        if (tree[now].value != -1) {
            complete = false;
        } else {
            tree[now].value = value;
        }
        cin >> in;
        if (in == "()") break;
        if (!complete) continue;
    }
    print(tree);
}

int main() {
    while (1) {
        cin >> in;
        if (cin.fail()) break;
        Run();
    }
    return 0;
}
