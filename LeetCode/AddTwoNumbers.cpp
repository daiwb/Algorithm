#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int add = 0;
        ListNode *ret(NULL), *cur(NULL);
        while (true) {
            int s = add;
            if (ret == NULL) {
                s += l1->val + l2->val;
            } else {
                if (l1 != NULL) s += l1->val;
                if (l2 != NULL) s += l2->val;
            }
            ListNode *t = new ListNode(s % 10);
            add = s / 10;
            
            if (ret == NULL) ret = t;
            else cur->next = t;
            cur = t;
            
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
            if (l1 == NULL && l2 == NULL) break;
        }
        if (add == 1) {
            ListNode *t = new ListNode(1);
            cur->next = t;
        }
        return ret;
    }
};
