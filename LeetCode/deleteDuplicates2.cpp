#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ret = NULL, *prev = NULL;
        if (head == NULL) return ret;
        while (head != NULL) {
            int now = head->val;
            if (head->next != NULL && head->next->val == now) {
                while (head != NULL && head->val == now) head = head->next;
            } else {
                if (ret == NULL) {
                    ret = head;
                    prev = head;
                } else {
                    prev->next = head;
                    prev = head;
                }
                head = head->next;
            }
        }
        if (prev != NULL) prev->next = NULL;
        return ret;
    }
};

int main() {
    ListNode mm[7];
    mm[0] = ListNode(1);
    mm[1] = ListNode(1);
    mm[2] = ListNode(1);
    mm[3] = ListNode(2);
    mm[4] = ListNode(3);
    mm[5] = ListNode(4);
    mm[6] = ListNode(5);
    REP(i,4) mm[i].next = &mm[i + 1];
    Solution s;
    ListNode *ret = s.deleteDuplicates(&mm[0]);
    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
    return 0;
}
