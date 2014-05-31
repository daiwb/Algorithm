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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;

        ListNode *cur = head, *prev;
        
        REP(i,m-1) {
            prev = cur;
            cur = cur->next;
        }

        ListNode *p = cur, *q, *nxt = cur->next, *nxt2;
        REP(i,n-m) {
            nxt2 = nxt->next;
            nxt->next = cur;
            cur = q = nxt;
            nxt = nxt2;
        }
        p->next = nxt2;
        if (m == 1) {
            return q;
        } else {
            prev->next = q;
            return head;
        }
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
