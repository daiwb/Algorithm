/*
zju 2042 Divisibility
00:00.69 484k
2004.08.05 by adai
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int testcase;
	cin >> testcase;
	for (int kase = 0; kase < testcase; kase ++){
		if(kase) cout << endl;

		int n, k;
		cin >> n >> k;
		
		int* input = new int[n];
		for(int i = 0; i < n; i ++) cin >> input[i];

		int* a = new int[k];
		int* b = new int[k];

		for(int i = 0; i < k; i ++) a[i] = 0;
		a[(input[0] + k * 10000) % k] = 1;

		for(int i = 1; i < n; i ++){
			for(int j = 0; j < k; j ++) b[j] = 0;
			for(int j = 0; j < k; j ++){
				if(a[j]){
					b[(j + input[i] + k * 10000) % k] = 1;
					b[(j - input[i] + k * 10000) % k] = 1;
				}
			}
			for(int j = 0; j < k; j ++) a[j] = b[j];
		}

		if(a[0] == 1) cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;

		delete []a;
		delete []b;
		delete []input;
	}
	return 0;
}
