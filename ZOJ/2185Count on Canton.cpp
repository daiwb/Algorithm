/*
 * zju 2185 Count on Canton
 * 00:00.00 444k
 * 2004.11.26 by adai
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cout << "TERM " << n << " IS ";
		int m = (int)((sqrt(1 + 8.0 * n) - 1) / 2);
		int num = m * (m + 1) / 2;
		if (num == n)
		{
			if (m % 2)
				cout << "1/" << m << endl;
			else
				cout << m << "/1" << endl;
			continue;
		}
		m ++;
		if (m % 2 == 0)
			cout << n - num << "/" << m + 1 - (n - num) << endl;
		else
			cout << m + 1 - (n - num) << "/" << n - num << endl;
	}
	return 0;
}
