/*
zju 2133 Tetris Alphabet
00:00.00 432k
2004.08.08 by adai
*/

#include <iostream>
using namespace std;

#ifdef WIN32
#define for if (0); else for
#endif

char mat[50][21];
char output[27];
int index;
int sign[26];

int main()
{	
	int kase;
	cin >> kase;
	for (int t = 0; t < kase; t ++)
	{
		if (t) cout << endl;
		int n;
		cin >> n;

		for (int i = 0; i < 26; i ++) sign[i] = 1;

		for (int i = 0; i < n; i ++)
		{
			cin >> mat[i];
			for (int j = 0; j < 20; j ++)
			{
				if (mat[i][j] != '.') sign[mat[i][j] - 'A'] = 0;
			}
		}

		int total = 0;
		for (int i = 0; i < 26; i ++)
		{
			if (sign[i] == 0) total ++;
		}
		
		index = 0;

		while (1) {
again:
			for (int i = 0; i < 26; i ++){
				if (sign[i] == 1) continue;
				int possible = 1;
				for (int j = 0; j < n - 1; j ++)
				{
					for (int s = 0; s < 20; s ++)
					{
						if (mat[j][s] == i + 'A')
						{
							if (mat[j + 1][s] != i + 'A' && mat[j + 1][s] != '.')
							{
								possible = 0;
								break;
							}
						}
					}
					if (possible == 0) break;
				}
				if (possible)
				{
					for (int j = 0; j < n; j ++)
					{
						for (int s = 0; s < 20; s ++)
						{
							if (mat[j][s] == i + 'A') mat[j][s] = '.';
						}
					}
					sign[i] = 1;
					total --;
					output[index ++] = i + 'A';
					if (total == 0) goto out;
					goto again;
				}
			}
		}
out:
		for(int i = 0; i < index; i ++) cout << output[i];
		cout << endl;
	}
	return 0;
}
