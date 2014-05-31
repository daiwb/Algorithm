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

TreeNode* n1 = NULL;
TreeNode* n2 = NULL;
TreeNode* pre = NULL;
int status, last;

class Solution {
public:
    void doit(TreeNode *node) {
        int v = node->val;
        if (status == 0) {
            status = 1;
        } else if (status == 1) {
            if (v < last) {
                status = 2;
                n1 = pre, n2 = node;
            }
        } else if (status == 2) {
            if (v < last) {
                status = 3;
                n2 = node;
            }
        } else {
            return;
        }
        last = v;
        pre = node;
    }
    void inorder(TreeNode *node) {
        if (node == NULL) return;
        inorder(node->left);
        doit(node);
        inorder(node->right);
    }
    void recoverTree(TreeNode *root) {
        status = 0;
        inorder(root);
        swap(n1->val, n2->val);
    }
};

int main() {
    Solution s = Solution();
    return 0;
}
