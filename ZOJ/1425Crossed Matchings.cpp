//zju 1425 Crossed Matchings

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int kase;
	cin >> kase;
	int i, j, ii, jj, imin, imax, jmin, jmax, temp;
	int num[101][101];
	while (kase --) {
		int n1, n2;
		cin >> n1 >> n2;
		int* a = new int[n1 + 1];
		int* b = new int[n2 + 1];
		for (i = 1; i <= n1; i ++) cin >> a[i];
		for (i = 1; i <= n2; i ++) cin >> b[i];

		memset(num, 0, sizeof(num));
		for (i = 1; i <= n1; i ++)
		for (j = 1; j <= n2; j ++) {
			if (num[i - 1][j] > num[i][j]) num[i][j] = num[i - 1][j];
			if (num[i][j - 1] > num[i][j]) num[i][j] = num[i][j - 1];
			if (a[i] == b[j]) {
				for (ii = 1; ii <= n1; ii ++) {
					if(a[i] == a[ii]) continue;
					for (jj = 1; jj <= n2; jj ++) {
						if (a[ii] == b[jj] && (ii < i && jj > j || ii > i && jj < j)) {
							imin = ii < i ? ii : i;
							imax = ii > i ? ii : i;
							jmin = jj < j ? jj : j;
							jmax = jj > j ? jj : j;
							temp = num[imin - 1][jmin - 1] + 2;
							if (temp > num[imax][jmax]) num[imax][jmax] = temp;
						}
					}
				}
			}
		}

		int max = 0;
		for (i = 1; i <= n1; i ++)
		for (j =1 ; j <= n2; j ++){
			if (num[i][j] > max) max = num[i][j];
		}
		cout << max << endl;

		delete []a;
		delete []b;
	}
	return 0;
}