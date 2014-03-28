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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return NULL;
        int cnt = 0;
        ListNode *cur = head, *last;
        while (cur != NULL) {
            ++cnt;
            last = cur;
            cur = cur->next;
        }
        k %= cnt;
        if (k == 0) return head;
        cur = head;
        REP(i,cnt-k-1) cur = cur->next;
        last->next = head;
        ListNode *res = cur->next;
        cur->next = NULL;
        return res;
    }
};

int main() {
    return 0;
}
