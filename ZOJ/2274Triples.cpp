/*
 * ZJU 2274 Triples
 * 00:00.96 440k
 * BY ADAI
 */

#include <iostream>
#include <cstring>
using namespace std;

#ifdef WIN32
#define for if(0);else for
#endif

#define MAXN 500

int a[MAXN];
int p[MAXN];

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main () {
	int n;
	while (1) {
		cin >> n;
		if (cin.fail()) break;
		for (int i = 0; i < n; i ++) cin >> a[i];

		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (gcd(a[i], a[j]) == 1) p[i] ++;
			}
		}

		int num = n * (n - 1) * (n - 2) / 6;
		int temp = 0;
		for (int i = 0; i < n; i ++) {
			temp += p[i] * (n - 1 - p[i]);
		}
		temp /= 2;
		num -= temp;
		
		cout << num << endl;
	}
	return 0;
}
