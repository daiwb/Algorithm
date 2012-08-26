/*
 * zju 1238 Guess the Number
 * 00:00.06 872k
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main() {
    int kase;
    char big[500001];

    scanf("%d", &kase);
    while (kase --) {
		scanf("%s", big);
		int len = strlen(big);
		if (len == 1) {
			if (big[0] == '1') printf("1\n");
			else if (big[0] == '4') printf("2\n");
			else printf("-1\n");
			continue;
		}
		
		int left = 1, right = 100000, mid;
		int res;
		int find = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			double temp = mid * log10((double)mid);
			res = (int)temp;
			res ++;
			if (res == len) {
				find = 1;
				break;
			}
			if (res > len) right = mid - 1;
			else left = mid + 1;
		}
		
		//cout << find << endl;

		if (!find) {
			printf("-1\n");
			continue;
		}

		res = mid;

		//cout << res << endl;
		int n = 0;
		for (int i = 0; i < len; i ++) {
			n = n * 10 + big[i] - '0';
			n %= res;
		}

		if (n % res) printf("-1\n");
		else printf("%d\n", res);
    }
    return 0;
}

