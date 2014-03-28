#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        deque<TreeLinkNode *> mm;
        mm.push_back(root);
        int cnt = 1;
        while (cnt != 0) {
            int t = 0;
            REP(i,cnt) {
                if (mm[i]->left != NULL) {
                    mm.push_back(mm[i]->left);
                    ++t;
                }
                if (mm[i]->right != NULL) {
                    mm.push_back(mm[i]->right);
                    ++t;
                }
                if (i + 1 < cnt) mm[i]->next = mm[i + 1];
            }
            REP(j,cnt) mm.pop_front();
            cnt = t;
        }
    }
};

int main() {
    return 0;
}
