/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *doit(ListNode* &head, int st, int ed) {
        if (st > ed) return NULL;
        int md = (st + ed) / 2;
        TreeNode *lTree = doit(head, st, md - 1);
        TreeNode *par = new TreeNode(head->val);
        head = head->next;
        TreeNode *rTree = doit(head, md + 1, ed);
        par->left = lTree;
        par->right = rTree;
        return par;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
        int len = 0;
        ListNode *t = head;
        while (t) {
            ++len;
            t = t->next;
        }
        return doit(head, 1, len);
    }
};
