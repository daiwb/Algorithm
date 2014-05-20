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
    TreeNode *doit(vector<int> &preorder, vector<int> &inorder, int st1, int ed1, int st2, int ed2) {
        int n = ed1 - st1 + 1;
        if (n == 0) return NULL;

        int idx = -1;
        FOR(i,st2,ed2) {
            if (inorder[i] == preorder[st1]) {
                idx = i;
                break;
            }
        }

        int num = idx - st2;

        TreeNode *root = new TreeNode(preorder[st1]);
        root->left = doit(preorder, inorder, st1 + 1, st1 + num, st2, idx - 1);
        root->right = doit(preorder, inorder, st1 + num + 1, ed1, idx + 1, ed2);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0) return NULL;
        return doit(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main() {
    VI p, q;
    int a[] = {1,2,4,3,5,6};
    int b[] = {4,2,1,5,3,6};
    REP(i,6) {
        p.PB(a[i]);
        q.PB(b[i]);
    }
    Solution s;
    TreeNode *res = s.buildTree(p, q);
    return 0;
}
