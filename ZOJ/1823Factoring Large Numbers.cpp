/*
zju 1823 Factoring Large Numbers
00:00.12 388k
2004.09.03 by adai
*/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void input(i64 &a)
{
	char temp[150];
    scanf("%s", temp);
    a = 0;
    for(int i = 0; temp[i] != '\0'; ++i)
        a = a * 10 + (int)(temp[i] - '0');
}
void print(i64 a)
{
    if(a > 9)
        print(a/10);
    printf("%d", (int)(a%10));
}

int main() {
	i64 t;
	while (1) {
        input(t);
		if (t < 0) break;
		
		if (t % 2 == 0) {
			while (t % 2 == 0) {
				printf("2\n");
				t /= 2;
			}
		}
		if (t % 3 == 0) {
			while (t % 3 == 0) {
				printf("3\n");
				t /= 3;
			}
		}

		i64 back = t;
		i64 sq = (i64)sqrt((double)t);
		i64 i;
		for (i = 5; i <= sq;) {
			if (t % i == 0) {
				while (t % i == 0) {
					print(i);
					printf("\n");
					t /= i;
				}
				back = t;
				sq = (i64)sqrt((double)t);
			}
			i += 2;
			if (t % i == 0) {
				while (t % i == 0) {
					print(i);
					printf("\n");
					t /= i;
				}
				back = t;
				sq = (i64)sqrt((double)t);
			}
			i += 4;
		}
		if (t == back) {
			print(back);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}