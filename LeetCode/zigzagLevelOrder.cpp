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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<VI> res;
        if (root == NULL) return res;
        deque<TreeNode *> que;
        que.PB(root);
        bool flag = true;
        while (!que.empty()) {
            flag = !flag;
            VI tmp;
            int n = que.size();
            REP(i,n) {
                tmp.PB(que[i]->val);
                if (que[i]->left != NULL) que.PB(que[i]->left);
                if (que[i]->right != NULL) que.PB(que[i]->right);
            }
            if (flag) reverse(tmp.begin(), tmp.end());
            res.PB(tmp);
            REP(i,n) que.pop_front();
        }
        return res;
    }
};

int main() {
    return 0;
}
