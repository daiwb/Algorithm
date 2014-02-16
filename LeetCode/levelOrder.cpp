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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        deque<pair<TreeNode, int> > mm;
        mm.push_back(make_pair(*root, 0));
        while (!mm.empty()) {
            TreeNode now = mm.front().first;
            int idx = mm.front().second;
            mm.pop_front();
            if (res.size() <= idx) res.push_back(vector<int>());
            res[idx].push_back(now.val);
            if (now.left != NULL) mm.push_back(make_pair(*now.left, idx + 1));
            if (now.right != NULL) mm.push_back(make_pair(*now.right, idx + 1));
        }
        return res;
    }
};