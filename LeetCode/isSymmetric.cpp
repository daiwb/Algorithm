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
    bool isok(TreeNode *lt, TreeNode *rt) {
        if (lt == NULL && rt == NULL) return true;
        if (lt == NULL && rt != NULL) return false;
        if (lt != NULL && rt == NULL) return false;
        if (lt->val != rt->val) return false;
        return isok(lt->left, rt->right) && isok(lt->right, rt->left);
    }
    
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return isok(root->left, root->right);
    }
};