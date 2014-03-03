#include <vector>
#include <iostream>
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

vector<vector<int> > res;

class Solution {
public:
    void doit(TreeNode *root, vector<int>& mm, int sum) {
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                mm.push_back(root->val);
                res.push_back(mm);
                mm.pop_back();
            }
            return;
        }
        mm.push_back(root->val);
        if (root->left != NULL) {
            doit(root->left, mm, sum - root->val);
        }
        if (root->right != NULL) {
            doit(root->right, mm, sum - root->val);
        }
        mm.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        res.clear();
        if (root != NULL) {
            vector<int> mm;
            doit(root, mm, sum);
        }
        return res;
    }
};

int main() {
    return 0;
}
