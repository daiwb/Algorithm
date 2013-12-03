#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        REP(i,n) {
            if (A[i] != elem) A[len++] = A[i];
        }
        return len;
    }
};

int main() {
    return 0;
}
