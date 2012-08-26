#include <iostream>
#include <string>
using namespace std;

int plist[10000],pcount=0;

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
	for (plist[pcount++]=2,i=3;i<10050;i++)
		if (prime(i))
			plist[pcount++]=i;
}

int mm[10005];

int main() {
    initprime();
    int num;
    cin >> num;
    mm[1] = 1;
    int m = 1;
    for (int i = 2; i <= num; ++i) {
        int n = i;
        int c = 0;
        for (int j = 0; j < pcount; ++j) {
            int p = plist[j];
            if (p * p > n) {
                if (n != 1) ++c;
                break;
            }
            while (n % p == 0) {
                ++c;
                n /= p;
            }
        }
        m = max(m, c + 1);
        mm[i] = c + 1;
    }
    cout << m << endl;
    for (int i = 1; i <= num; ++i) {
        if (i != 1) cout << " ";
        cout << mm[i];
    }
    cout << endl;
    return 0;
}
