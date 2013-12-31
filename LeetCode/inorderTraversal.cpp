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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;
        vector<int> lt = inorderTraversal(root->left);
        vector<int> rt = inorderTraversal(root->right);
        for (int i = 0; i < lt.size(); ++i) ret.push_back(lt[i]);
        ret.push_back(root->val);
        for (int i = 0; i < rt.size(); ++i) ret.push_back(rt[i]);
        return ret;
    }
};