#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int len = 1;
        FOR(i,1,n-1) {
            if (A[i] != A[i - 1]) A[len++] = A[i];
        }
        return len;
    }
};

int main() {
    return 0;
}
