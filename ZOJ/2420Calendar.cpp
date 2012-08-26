/**
 * ZOJ 2420 Calendar
 *
 * 2005/04/26 By adai
 */

#include <iostream>
#include <string>
using namespace std;

int n;
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char week[7][20] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int y, m, d;

int IsLeapYear(int year) {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return 1;
	return false;
}

int Run() {
	++n;
	int w = n;
	for (int i = 2000; ; ++i) {
		if (IsLeapYear(i)) {
			if (n - 366 <= 0) {
				y = i;
				break;
			}
			else n -= 366;
		}
		else {
			if (n - 365 <= 0) {
				y = i;
				break;
			}
			else n -= 365;
		}
	}
	if (IsLeapYear(y)) month[1] = 29;
	else month[1] = 28;
	for (int i = 0; i < 12; ++i) {
		if (n - month[i] <= 0) {
			m = i + 1;
			break;
		}
		else n -= month[i];
	}
	d = n;
	cout << y << '-';
	if (m < 10) cout << 0;
	cout << m << '-';
	if (d < 10) cout << 0;
	cout << d;
	cout << ' ' << week[(w + 5) % 7] << endl;
	return 0;
}

int main() {
	//for (int i = 0; i < 7; ++i) cout << week[i] << endl;
	while (cin >> n && n != -1) {
		Run();
	}
	return 0;
}
