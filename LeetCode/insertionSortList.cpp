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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return head;
        ListNode *cur = head->next, *last = head;
        while (cur != NULL) {
            ListNode *next = cur->next;
            if (cur->val <= head->val) {
                cur->next = head;
                head = cur;
            } else if (cur->val >= last->val) {
                last = cur;
            } else {
                ListNode *t = head;
                while (true) {
                    if (cur->val > t->val && cur->val <= t->next->val) {
                        cur->next = t->next;
                        t->next = cur;
                        break;
                    }
                    t = t->next;
                }
            }
            last->next = next;
            cur = next;
        }
        return head;
    }
};