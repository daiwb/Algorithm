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
    TreeNode *doit(vector<int> &inorder, vector<int> &postorder, int st1, int ed1, int st2, int ed2) {
        int n = ed1 - st1 + 1;
        if (n == 0) return NULL;

        int idx = -1;
        FOR(i,st1,ed1) {
            if (inorder[i] == postorder[ed2]) {
                idx = i;
                break;
            }
        }

        int num = idx - st1;

        TreeNode *root = new TreeNode(postorder[ed2]);
        root->left = doit(inorder, postorder, st1, idx - 1, st2, st2 + num - 1);
        root->right = doit(inorder, postorder, idx + 1, ed1, st2 + num, ed2 - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        if (n == 0) return NULL;
        return doit(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};

int main() {
    VI p, q;
    int a[] = {4,2,1,5,3,6};
    int b[] = {4,2,5,6,3,1};
    REP(i,6) {
        p.PB(a[i]);
        q.PB(b[i]);
    }
    Solution s;
    TreeNode *res = s.buildTree(p, q);
    return 0;
}
