/*
  ID: dwb19832
  PROG: fence9
  LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");

int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        a ^= b ^= a ^= b;
    }
    return a;
}

int doit(int n, int m) {
    int g = gcd(n, m);
    int ret = (n + 1) * (m + 1);
    ret -= (g + 1);
    ret -= (n - 1 + m - 1 + 1) << 1;
    return ret >> 1;
}

int main() {
    int n, m, p;
    fin >> n >> m >> p;
    int ret;
    if (n == 0 || n == p) ret = doit(m, p);
    else if (p > n) {
        ret = doit(n, m) + doit(p - n, m) + m - 1;
    }
    else ret = doit(n, m) - doit(n - p, m) - gcd(n - p, m) + 1;
    fout << ret << endl;
    return 0;
}
