#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* root = head->next;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL && cur->next != NULL) {
            ListNode* n1 = cur->next;
            ListNode* n2 = n1->next;
            if (pre != NULL) pre->next = n1;
            n1->next = cur;
            cur->next = n2;
            pre = cur;
            cur = n2;
        }

        return root;
    }
};

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    n1.next = &n2;
    ListNode n3 = ListNode(3);
    n2.next = &n3;
    ListNode n4 = ListNode(4);
    n3.next = &n4;

    Solution s = Solution();
    ListNode* cur = s.swapPairs(&n1);
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}
