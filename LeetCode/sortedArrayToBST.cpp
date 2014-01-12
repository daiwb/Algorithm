#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *doit(vector<int> &num, int lt, int rt) {
        if (lt > rt) return NULL;

        int mt = (lt + rt) / 2;
        TreeNode* ret = new TreeNode(num[mt]);
        ret->left = doit(num, lt, mt - 1);
        ret->right = doit(num, mt + 1, rt);

        return ret;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return doit(num, 0, num.size() - 1);
    }
};

int main() {
    return 0;
}
