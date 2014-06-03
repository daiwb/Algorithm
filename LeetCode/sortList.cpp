#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = head, *q = head;
        while (q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        
        q = p->next;
        p->next = NULL;
        p = head;
        
        p = sortList(p);
        q = sortList(q);
        
        ListNode *root = new ListNode(0), *cur = root;
        while (p != NULL || q != NULL) {
            if (p == NULL) {
                cur->next = q;
                cur = q;
                q = q->next;
            } else if (q == NULL) {
                cur->next = p;
                cur = p;
                p = p->next;
            } else if (p->val < q->val) {
                cur->next = p;
                cur = p;
                p = p->next;
            } else {
                cur->next = q;
                cur = q;
                q = q->next;
            }
        }
        return root->next;
    }
};

int main() {
    Solution s;
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(4);
    ListNode *n3 = new ListNode(2);
    ListNode *n4 = new ListNode(1);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode *c = s.sortList(n1);
    while (c != NULL) {
        cout << c->val << endl;
        c = c->next;
    }
    return 0;
}
