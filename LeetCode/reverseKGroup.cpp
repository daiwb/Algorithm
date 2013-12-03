#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || k <= 1) return head;

        ListNode* root = head;
        REP(i,k-1) {
            root = root->next;
            if (root == NULL) break;
        }
        if (root == NULL) return head;

        ListNode* cur = head;
        ListNode* pre = NULL;
        while (cur != NULL) {
            ListNode* last = cur;
            REP(i,k-1) {
                last = last->next;
                if (last == NULL) break;
            }
            if (last == NULL) break;

            ListNode* nxt = last->next;
            if (pre != NULL) pre->next = last;

            ListNode* p = cur;
            ListNode* itr = cur->next;
            REP(i,k-1) {
                ListNode* n = itr->next;
                itr->next = p;
                p = itr;
                itr = n;
            }
            cur->next = nxt;
            pre = cur;
            cur = nxt;
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
    ListNode n5 = ListNode(5);
    n4.next = &n5;

    Solution s = Solution();
    ListNode* cur = s.reverseKGroup(&n1, 2);
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}
