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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = head, *p = head, *prev = head;
        if (ret == NULL || ret->next == NULL) return ret;
        int last = head->val - 1;
        while (head != NULL) {
            if (head->val != last) {
                last = head->val;
                p->val = last;
                prev = p;
                p = p->next;
            }
            head = head->next;
        }
        prev->next = NULL;
        return ret;
    }
};