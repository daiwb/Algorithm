/*
 * ZJU 1495 Stacking Tower
 * 00:00.00 836k
 * 2005.03.16 by adai
 */

#include <iostream>
using namespace std;

int n, wid;
int a[100];

int main()
{
	while (cin >> n && n)
	{
		int i;
		for (i = 0; i < n; ++i) cin >> a[i];

		wid = n;
		i = 0;
		while (1)
		{
			if (a[i] > wid)
			{
				++i;
				--wid;
			}
			else wid = a[i++] - 1;
			if (wid == 0) break;
		}
		cout << n - i << endl;
	}
	return 0;
}