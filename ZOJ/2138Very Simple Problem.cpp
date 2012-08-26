/*
zju 2138 Very Simple Problem
00:00.01 476k
2004.08.08 by adai
*/

#include <iostream>
using namespace std;

int mat[101][101];
int a[101];
int b[101];

int main()
{
	int kase;
	cin >> kase;
	for (int t = 0; t < kase; t ++)
	{
		if (t) cout << endl;
		int n, p;
		cin >> n >> p;
		int half = (n + 1) / 2;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= p; j ++)
			{
				cin >> mat[i][j];
			}
			a[i] = b[i] = 0;
		}

		for (int i = 1; i <= n; i ++)
		{
			int minn = mat[i][1], maxn = mat[i][1];
			for (int j = 2; j <= p; j ++)
			{
				if (mat[i][j] < minn) minn = mat[i][j];
				if (mat[i][j] > maxn) maxn = mat[i][j];
			}
			for (int j = 1; j <= p; j ++)
			{
				if (mat[i][j] == minn) a[j] ++;
				if (mat[i][j] == maxn) b[j] = 1;
			}
		}
		int sign = 0;
		for (int i = 1; i <= p; i ++)
		{
			if (a[i] >= half && b[i] == 0){
				if (sign) cout << " " << i;
				else
				{
					cout << i;
					sign = 1;
				}
			}
		}
		if (sign == 0) cout << "0";
		cout << endl;
	}
	return 0;
}
