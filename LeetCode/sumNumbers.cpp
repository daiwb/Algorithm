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
    int sum;
    void doit(TreeNode *root, int cur) {
        if (root->left == NULL && root->right == NULL) {
            sum += cur + root->val;
            return;
        }
        if (root->left != NULL) doit(root->left, (cur + root->val) * 10);
        if (root->right != NULL) doit(root->right, (cur + root->val) * 10);
    }
    int sumNumbers(TreeNode *root) {
        if (root == NULL) return 0;
        sum = 0;
        doit(root, 0);
        return sum;
    }
};