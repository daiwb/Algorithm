//ac

#include <iostream>
using namespace std;

long long plist[10000],pcount=0;

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
	return n>1;
}

void initprime(){
	int i;
	for (plist[pcount++]=2,i=3;i<50000;i++)
		if (prime(i))
			plist[pcount++]=i;
}

bool f(long long n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	long long num = 3;
	long long n2 = (long long)sqrt((double) n) + 1;
	for (long long i = 2; i <= n2; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void run() {
	long long n;
	cin >> n;
	long long n2 = (long long)sqrt((double) n) + 1;
	for (int i = 0; i < pcount; ++i) {
		if (plist[i] > n2) break;
		if (n % plist[i] == 0) {
			if (f(n / plist[i])) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
			return;
		}
	}
	printf("No\n");
}

int main() {
	initprime();
	int n;
	for (scanf("%lld", &n); n; --n) {
		run();
	}
}

