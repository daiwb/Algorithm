/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        ListNode *ret, *res;
        if (l1->val < l2->val) {
            ret = l1;
            l1 = l1->next;
            res = ret;
        } else {
            ret = l2;
            l2 = l2->next;
            res = ret;
        }
        
        while (true) {
            if (l1 == NULL) {
                ret->next = l2;
                break;
            } else if (l2 == NULL) {
                ret->next = l1;
                break;
            }
            
            if (l1->val < l2->val) {
                ret->next = l1;
                ret = l1;
                l1 = l1->next;
            } else {
                ret->next = l2;
                ret = l2;
                l2 = l2->next;
            }
        }
        
        return res;
    }
};