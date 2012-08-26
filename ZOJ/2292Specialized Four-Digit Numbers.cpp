/**
 * ZOJ 2292 Specialized Four-Digit Numbers
 *
 * 2005/04/11 By adai
 */

#include <iostream>
using namespace std;

int ndec[4], nduo[4], nhex[4];
int num[3];

int Init() {
	ndec[0] = 2, ndec[1] = 9,  ndec[2] = 9,  ndec[3] = 1;
	nduo[0] = 1, nduo[1] = 8,  nduo[2] = 9,  nduo[3] = 3;
	nhex[0] = 0, nhex[1] = 11, nhex[2] = 10, nhex[3] = 15;
	num[0] = 21, num[1] = 21, num[2] = 36;
	return 0;
}

int add(int a[4], int base, int index) {
	int aa = 1;
	for (int i = 3; i >= 0; --i) {
		a[i] += aa;
		num[index] += aa;
		if (a[i] == base) {
			num[index] -= base;
			a[i] = 0;
			aa = 1;
		}
		else aa = 0;
	}
	return 0;
}

int Run() {
	for (int i = 2992; i <= 9999; ++i) {
		add(ndec, 10, 0);
		add(nduo, 12, 1);
		add(nhex, 16, 2);
		if (num[0] == num[1] && num[1] == num[2]) cout << i << endl;
	}
	return 0;
}

int main() {
	Init();
	Run();
	return 0;
}
