/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int doit(TreeNode *root) {
        if (root == NULL) return 0;
        int h1 = doit(root->left);
        int h2 = doit(root->right);
        if (h1 == -1 || h2 == -1) return -1;
        if (abs(h1 - h2) > 1) return -1;
        return max(h1, h2) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == NULL) return true;
        int h1 = doit(root->left);
        int h2 = doit(root->right);
        if (h1 == -1 || h2 == -1 || abs(h1 - h2) > 1) return false;
        return true;
    }
};