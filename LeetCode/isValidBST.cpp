#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLess(TreeNode *root, int num) {
        if (root == NULL) return true;
        if (root->val >= num) return false;
        return isLess(root->left, num) && isLess(root->right, num);
    }
    bool isMore(TreeNode *root, int num) {
        if (root == NULL) return true;
        if (root->val <= num) return false;
        return isMore(root->left, num) && isMore(root->right, num);
    }
    bool isValidBST(TreeNode *root) {
        if (root == NULL) return true;
        
        if (!isLess(root->left, root->val)) return false;
        if (!isMore(root->right, root->val)) return false;

        return isValidBST(root->left) && isValidBST(root->right);
    }
};

int main() {
    return 0;
}
