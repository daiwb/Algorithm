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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode* n1 = head;
        ListNode* n2 = head;
        
        while (true) {
            n1 = n1->next;
            if (n1 == NULL) return NULL;
            
            n2 = n2->next;
            if (n2 == NULL) return NULL;
            n2 = n2->next;
            if (n2 == NULL) return NULL;
            
            if (n1 == n2) {
                n1 = head;
                while (n1 != n2) {
                    n1 = n1->next;
                    n2 = n2->next;
                }
                return n1;
            }
        }
    }
};

int main() {
    return 0;
}
