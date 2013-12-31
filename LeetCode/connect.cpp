/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        TreeLinkNode *pt1 = root->left;
        TreeLinkNode *pt2 = root->right;
        while (pt1 != NULL) {
            pt1->next = pt2;
            pt1 = pt1->right;
            pt2 = pt2->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
