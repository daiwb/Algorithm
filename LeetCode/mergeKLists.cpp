#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        int k = lists.size();
        priority_queue<pair<int, int> > que;
        REP(i,k) {
            if (lists[i] != NULL) {
                que.push(make_pair(-lists[i]->val, i));
            }
        }
        ListNode* cur = NULL;
        ListNode* root = NULL;
        while (!que.empty()) {
            int idx = que.top().second;
            que.pop();
            if (cur == NULL) {
                cur = lists[idx];
                root = lists[idx];
            } else {
                cur->next = lists[idx];
                cur = cur->next;
            }
            lists[idx] = lists[idx]->next;
            if (lists[idx] != NULL) {
                que.push(make_pair(-lists[idx]->val, idx));
            }
        }
        return root;
    }
};

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(4);
    n1.next = &n2;
    ListNode n3 = ListNode(5);
    n2.next = &n3;
    
    ListNode n4 = ListNode(2);
    ListNode n5 = ListNode(3);
    n4.next = &n5;

    vector<ListNode *> lists;
    lists.push_back(&n1);
    lists.push_back(&n4);

    Solution s = Solution();

    ListNode* cur = s.mergeKLists(lists);
    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    
    return 0;
}
