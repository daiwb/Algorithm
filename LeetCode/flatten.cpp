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
    TreeNode *cur;
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        cur = root;
        TreeNode *rTree = root->right;
        if (root->left != NULL) {
            flatten(root->left);
            root->right = root->left;
            cur->right = rTree;
        }
        root->left = NULL;
        flatten(root->right);
    }
};