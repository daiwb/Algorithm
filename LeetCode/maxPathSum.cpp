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
    int mx;
    int doit(TreeNode *root) {
        if (root == NULL) return 0;
        int v = root->val;
        int lt = max(0, doit(root->left));
        int rt = max(0, doit(root->right));
        mx = max(mx, v + lt + rt);
        return v + max(lt, rt);;
    }
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        mx = root->val;
        doit(root);
        return mx;
    }
};

int main() {
    return 0;
}
