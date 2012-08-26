//zju 2105 Number Sequence

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
	int A, B, n;
	int from, to;
	int mat[7][7];
	int num[7][7];
	while(1){
		cin >> A >> B >> n;
		if(A == 0 && B == 0 && n == 0) break;
		A %= 7;
		B %= 7;

		if(n <= 2){
			cout << 1 << endl;
			continue;
		}
		n -= 2;
		
		memset(mat, 0, sizeof(mat));
		memset(num, 0, sizeof(num));

		mat[1][1] = 2;
		from = 1;
		to = 1;

		int count = 1;
		int res;
		int sign = 0;
		while(1){
			if(sign) res = mat[from][to];
			else{
				num[from][to] = count ++;
				res = (A * to + B * from) % 7;
				mat[from][to] = res;
				if(num[to][res] > 0){
					int d = count - num[to][res];
					n %= d;
					sign = 1;
				}
			}
			n --;
			if(n <= 0) break;
			from = to;
			to = res;
		}
		if(n < 0) res = to;
		cout << res << endl;
	}
	return 0;
}
