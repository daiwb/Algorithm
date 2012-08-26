/*
 * ZJU 2284 Inversion Number
 * 00:00.02 872k
 */

#include <iostream>
#include <cstdio>
using namespace std;

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void input(i64 &a)
{
	char temp[100];
    cin >> temp;
    a = 0;
    for(int i = 0; temp[i] != '\0'; ++i)
        a = a * 10 + (int)(temp[i] - '0');
}
void print(i64 a)
{
    if(a > 9)
        print(a/10);
    cout << (int)(a%10);
}

i64 n, m;
i64 mat[21][201];

i64 count(i64 n, i64 m) {
	if (m < 0) return 0;
	if (n * (n - 1) / 2 < m) return 0;
	if (mat[n][m] != -1) return mat[n][m];
	if (m == 0) return 1;
	if (m == 1) return n - 1;
	i64 num = 0;
	for (i64 i = 1; i <= n; i ++) {
		if (mat[n - 1][m + 1 - i] == -1) mat[n - 1][m + 1 - i] = count(n - 1, m + 1 - i);
		num += mat[n - 1][m + 1 - i];
	}
	return num;
}

int main() {
	for (i64 i = 0; i < 21; i ++) {
		for (i64 j = 0; j < 201; j ++) mat[i][j] = -1;
	}
	while (1) {
		input(n);
		input(m);
		if (n == 0 && m == 0) break;
		i64 res = count(n, m);
		print(res);
		printf("\n");
	}
	return 0;
}
