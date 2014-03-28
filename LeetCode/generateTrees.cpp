#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode *> doit(int lt, int rt) {
        vector<TreeNode *> res;
        if (lt > rt) {
            res.push_back(NULL);
            return res;
        }
        FOR(i,lt,rt) {
            vector<TreeNode *> lc = doit(lt, i - 1);
            vector<TreeNode *> rc = doit(i + 1, rt);
            REP(j1,lc.size()) {
                REP(j2,rc.size()) {
                    TreeNode *t = new TreeNode(i);
                    t->left = lc[j1];
                    t->right = rc[j2];
                    res.push_back(t);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n) {
        return doit(1, n);
    }
};

int main() {
    return 0;
}
