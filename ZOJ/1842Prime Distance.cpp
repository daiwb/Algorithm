#include <iostream>
#include <string>
using namespace std;

long long pn, prime[4800];

void init()
{
    prime[0] = 2; prime[1] = 3; pn = 2;
    for (int n = 5, i; n <= 47000; n += 2) {
        for (i = 1; prime[i] * prime[i] <= n && n % prime[i]; i ++);
        if (prime[i] * prime[i] > n) prime[pn ++] = n;
    }
}

char bb[1000010];

int main()
{       
    long long L, U, cl[2], di[2], last;
    init();
    
    while (cin >> L >> U) {
        if (L == 1) L ++;
        memset(bb, 0, sizeof(bb[0]) * (U - L + 1));
        cl[0] = cl[1] = 0; di[0] = di[1] = 0;
        for (long long i = 0, j; prime[i] * prime[i] <= U; i ++) {
            j = L / prime[i] + (L % prime[i] > 0);
            if (j == 1) j ++; 
            for (j *= prime[i]; j <= U; j += prime[i]) bb[j - L] = 1;
        }
        last = 0;
        for (long long i = L; i <= U; i ++) {
            if (!bb[i - L]) {
                if (last) {
                    if (!cl[0] || cl[0] && i - last < cl[1] - cl[0])
                        cl[0] = last, cl[1] = i;
                    if (!di[0] || di[0] && i - last > di[1] - di[0])
                        di[0] = last, di[1] = i;
                }
                last = i;
            }
        }
        if (cl[0])
            cout << cl[0] << "," << cl[1] << " are closest, " << di[0] << "," << di[1] << " are most distant." << endl;
        else cout << "There are no adjacent primes." << endl;
    }
    
    return 0;
}       
