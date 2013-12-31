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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ret;
        if (root == NULL) return ret;
        ret.push_back(root->val);
        vector<int> lt = preorderTraversal(root->left);
        vector<int> rt = preorderTraversal(root->right);
        for (int i = 0; i < lt.size(); ++i) ret.push_back(lt[i]);
        for (int i = 0; i < rt.size(); ++i) ret.push_back(rt[i]);
        return ret;
    }
};
