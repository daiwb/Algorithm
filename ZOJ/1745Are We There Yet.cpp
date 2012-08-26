/**
 * ZOJ 1745 Are We There Yet?
 *
 * 2005/05/02 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int cookie, kase = 0;;

int Run() {
	if (kase++) cout << endl;
	int last = 0, now;
	while (cin >> now) {
		cout << "Moving from " << last << " to " << now << ": ";
		if (now == cookie) {
			cout << "found it!" << endl;
			break;
		}
		if (abs(now - cookie) < abs(last - cookie)) cout << "warmer." << endl;
		else if (abs(now - cookie) > abs(last - cookie)) cout << "colder." << endl;
		else cout << "same." << endl;
		last = now;
	}
	return 0;
}

int main() {
	while (cin >> cookie && cookie != 5280) {
		Run();
	}
	return 0;
}
