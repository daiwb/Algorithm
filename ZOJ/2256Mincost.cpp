/*
 * zju 2256 Mincost
 * author: adai
 */

#include <iostream>
using namespace std;

int main () {
	cout.setf(ios::fixed);
	cout.precision(1);
	int mile;
	while (1) {
		cin >> mile;
		if (!mile) break;
		double cost = 0;
		if (mile <= 4) {
			cost += 10;
			if ((int)cost * 10 == (int)(cost * 10)) cout << (int)cost << endl;
			else cout << cost << endl;
			continue;
		}
		else if (mile <= 8) {
			cost += 10 + (mile - 4) * 2;
			if ((int)cost * 10 == (int)(cost * 10)) cout << (int)cost << endl;
			else cout << cost << endl;
			continue;
		}
		cost += (mile / 8) * 18;
		mile %= 8;
		double temp = 0;
		if (mile <= 4) temp += 10;
		else if (mile <= 8) temp += 10 + (mile - 4) * 2;
		else temp += 10 + 8 + (mile - 8) * 2.4;
		if (temp > mile * 2.4) cost += mile * 2.4;
		else cost += temp;
		if ((int)cost * 10 == (int)(cost * 10)) cout << (int)cost << endl;
		else cout << cost << endl;
	}
	return 0;
}