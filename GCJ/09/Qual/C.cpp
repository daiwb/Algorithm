#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define LEN 19
#define MOD 10000

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string str;
string text = "welcome to code jam";
int mm[25][505];
int len;

int dp(int now, int idx) {
	int& ret = mm[now][idx];
	if (ret != -1) return ret;

	if (now == LEN) {
		return ret = 1;
	}

	ret = 0;

	FOR(i,idx+1,len-1) {
		if (str[i] != text[now]) continue;
		ret = (ret + dp(now + 1, i)) % MOD;
	}

	return ret;
}

void run() {
	getline(cin, str);
	len = str.length();
	memset(mm, -1, sizeof(mm));
	int res = 0;
	REP(i,len) {
		if (str[i] == text[0]) {
			res = (res + dp(1, i)) % MOD;
		}
	}
	if (res <= 9) cout << "000";
	else if (res <= 99) cout << "00";
	else if (res <= 999) cout << "0";
	cout << res << endl;
}

int main() {
	int n;
	cin >> n;
	getline(cin, str);
	REP(k,n) {
		cout << "Case #" << k + 1 << ": ";
		run();
	}
	return 0;
}
