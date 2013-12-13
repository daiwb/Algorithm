#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int lt = 0, rt = n - 1;
        while (lt <= rt) {
            int mt = (lt + rt) / 2;
            if (A[mt] < target) lt = mt + 1;
            else rt = mt - 1;
        }
        if (lt == rt) return A[lt] == target ? lt : lt + 1;
        return rt + 1;
    }
};

int main() {
    return 0;
}
