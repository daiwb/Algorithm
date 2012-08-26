#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define N 100000000

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;
 
int primes[N];

void initPrimes() {
    for (LL i = 0; i < N; ++i) primes[i] = 1;
    for (LL i=2; i * i < N; ++i) {
        if (primes[i]) {
            for (LL t = i + i; t < N; t += i) primes[t]=0;
        }
    }
}

int Primes (LL n) {
    if (n < N) return primes[n];
    return 0;
}

LL s2i(string s) {
  stringstream ss;
  ss << s;
  LL res;
  ss >> res;
  return res;
}

string i2s(LL n) {
  stringstream ss;
  ss << n;
  string res;
  ss >> res;
  return res;
}

LL concat (LL a, LL b) {
    LL c = b;
    LL d = a;
    while (c > 0) {
        d *= 10;
        c /= 10;
    }
    d += b;
    return d;
}
 
int main () {
    initPrimes();
    LL p1 = 0;
    LL p2 = 0;
    LL p3 = 0;
    LL p4 = 0;
    LL p5 = 0;

    LL t1, t2, t3, t4;

    for (p1 = 3; p1 < N; p1 += 2) {
        if (!Primes(p1)) continue;
        for (p2 = p1; (t1 = concat(p2, p1)) < N; p2 += 2) {
            if (!Primes(p2) || !Primes(t1) || !Primes(concat(p1,p2))) continue;
            for (p3 = p2; (t2 = concat(p3, p2)) < N; p3 += 2) {
                if (!Primes(p3) || !Primes(t2) || !Primes(concat(p2, p3)) || !Primes(concat(p1, p3)) || !Primes(concat(p3, p1))) continue;
                for (p4 = p3; (t3 = concat(p4, p3)) < N; p4 += 2) {
                    if (!Primes(p4) || !Primes(t3) || !Primes(concat(p3, p4)) || !Primes(concat(p1, p4)) || !Primes(concat(p4, p1))
                        || !Primes(concat(p2, p4)) || !Primes(concat(p4, p2))) continue;
                    for (p5 = p4; (t4 = concat(p5, p4)) < N; p5 += 2) {
                        if (!Primes(p5) || !Primes(t4) || !Primes(concat(p4, p5)) || !Primes(concat(p1, p5)) || !Primes(concat(p5, p1))
                            || !Primes(concat(p2, p5)) || !Primes(concat(p5, p2)) || !Primes(concat(p3, p5)) || !Primes(concat(p5, p3))) continue;
                        printf("%lld, %lld, %lld, %lld, %lld (s=%lld)\n", p1, p2, p3, p4, p5, p1 + p2 + p3 + p4 + p5);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Pas d'autres solutions?!\n");
    return 0;
}