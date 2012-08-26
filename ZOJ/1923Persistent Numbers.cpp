/*ZJU 1923 Persistent Numbers
2004.04.24 By adai
00:00.15 436K*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char input[1001], temp[1001] = {0};
	long i, j, len, m, t, n, sign;
	while (cin >> input) {
		if (strcmp(input, "-1") == 0) break;
		len = strlen(input);
		if (len == 1) {
			cout << 1 << input << endl;
			continue;
		}
		long a[10] = {0};
		n = 9;
		while (1) {
			m = j = sign = 0;
			for (i = 0; i < len; i ++) {
				m = 10 * m + input[i] - '0';
				t = m / n;
				if(t == 0) {
					if (sign == 1) temp[j ++] = '0';
					else sign = 1;
				}
				else {
					temp[j ++] = t + '0';
					sign = 1;
				}
				m = m % n;
			}
			if (m == 0) {
				temp[j] = '\0';
				strcpy(input, temp);
				len = j;
				a[n] ++;
			}
			else{
				n --;
			}
			if (n == 1) break;
		}
		if (len > 1) {
			cout << "There is no such number." << endl;
			continue;
		}
		for (i = 2; i <= 9; i ++) {
			for (j = 0; j < a[i]; j ++) cout << i;
		}
		cout << endl;
	}
	return 0;
}
