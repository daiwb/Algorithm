/**
 * ZOJ 1689 Calling Extraterrestrial Intelligence Again
 */

#include <iostream>
#include <string>
using namespace std;

int m, a, b;
int plist[20000], pcount=0;
int state[110000][2];

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
	for (plist[pcount++]=2,i=3;i<=100000;i++)
		if (prime(i))
			plist[pcount++]=i;
}

void Run()
{
	memset(state, -1, sizeof(state));
	for (int i = 0; i < pcount; i ++)
		state[plist[i]][0] = plist[i], state[plist[i]][1] = 1;
	for (int i = 0; i < pcount; i ++)
	for (int j = 0; j <= i && plist[j] * plist[i] <= 100000; j ++)
		state[plist[i] * plist[j]][0] = plist[i], state[plist[i] * plist[j]][1] = plist[j];
}

int main()
{
	initprime();
	Run();
	for (cin >> m >> a >> b; m || a || b; cin >> m >> a >> b) {
		int res;
		for (res = m; res; res --) {
			if (state[res][0] >= 0 && a * state[res][0] <= b * state[res][1])
				break;
		}
		cout << state[res][1] << " " << state[res][0] << endl;
	}
	return 0;
}
