#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *pre = NULL, *cur = head;
        REP(i,n-1) cur = cur->next;
        while (cur->next != NULL) {
            if (pre == NULL) pre = head;
            else pre = pre->next;
            cur = cur->next;
        }
        if (pre == NULL) return head->next;
        pre->next = pre->next->next;
        return head;
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

    ListNode *head = &n1;
    

    Solution s = Solution();
    ListNode *res = s.removeNthFromEnd(head, 2);

    while (res != NULL) {
        cout << res->val << endl;
        res = res->next;
    }
    
    return 0;
}
