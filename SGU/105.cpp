//Div 3

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n, res;
	scanf("%d", &n);
	res = (n / 3) * 2;
	n %= 3;
	if (n == 2) res ++;
	printf("\n", res);
	return 0;
}
