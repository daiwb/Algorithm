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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        ListNode *cur = head, *pre = NULL, *phead = NULL;
        while (cur != NULL && cur->val < x) {
            pre = cur;
            cur = cur->next;
        }
        if (cur == NULL) return head;
        ListNode *tmp = cur, *q = cur;
        if (pre != NULL) phead = head;
        cur = cur->next;
        while (cur != NULL) {
            if (cur->val < x) {
                if (pre == NULL) {
                    pre = cur;
                    if (phead == NULL) phead = cur;
                } else {
                    pre->next = cur;
                    pre = pre->next;
                }
            } else {
                tmp->next = cur;
                tmp = tmp->next;
            }
            cur = cur->next;
        }
        tmp->next = NULL;
        if (pre == NULL) return q;
        pre->next = q;
        return phead;
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
