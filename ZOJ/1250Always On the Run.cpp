/*
 * ZJU 1250 Always On the Run
 * 00:00.03 852k
 */

#include <iostream>
#include <cstring>
using namespace std;

int n, k, kase = 1;
int price[10][10][30], period[10][10];
int ret[10], mm[10];

int main()
{
	memset(price, 0, sizeof(price));
	while (1)
	{
		cin >> n >> k;
		if (!n && !k) break;

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if (i == j) continue;
				int d;
				cin >> d;
				period[i][j] = d;
				for(int ii = 0; ii < d; ii++)
					cin >> price[i][j][ii];
			}
		}
		
		memset(ret, 0, sizeof(ret));
		for(int i = 1; i < n; i++)
		{
			int temp = price[0][i][0];
			if (temp) ret[i] = temp;
		}
		for(int day = 1; day < k; day++)
		{
			memset(mm, 0, sizeof(mm));
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					if (i == j || ret[j] == 0) continue;
					int temp = price[j][i][day % period[j][i]];
					if (temp)
					{
						if (mm[i] == 0 || ret[j] + temp < mm[i]) mm[i] = ret[j] + temp;
					}
				}
			}
			memcpy(ret, mm, sizeof(ret[0]) * n);
		}
		cout << "Scenario #" << kase++ << endl;
		if (ret[n - 1] > 0) cout << "The best flight costs " << ret[n - 1] << "." << endl << endl;
		else cout << "No flight possible." << endl << endl;
	}
	return 0;
}
