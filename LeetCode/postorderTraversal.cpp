#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<TreeNode> mm;
        vector<int> res;
        if (root == NULL) return res;

        mm.push_back(*root);
        while (!mm.empty()) {
            TreeNode now = mm.back();
            mm.pop_back();
            res.push_back(now.val);
            if (now.left != NULL) mm.push_back(*now.left);
            if (now.right != NULL) mm.push_back(*now.right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
