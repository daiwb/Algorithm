/*
 * ZJU 1563 Pearls
 * 00:00.00 840k
 */

#include <iostream>
using namespace std;

int kase, num, mm[100][2], tt[100][2];

int main()
{
	cin >> kase;
	while (kase--)
	{
		cin >> num;
		for (int i = 0; i < num; ++i) {
			cin >> mm[i][0] >> mm[i][1];
		}
		tt[0][0] = mm[0][0];
		tt[0][1] = (mm[0][0] + 10) * mm[0][1];
		for (int i = 1; i < num; ++i)
		{
			tt[i][0] = tt[i - 1][0] + mm[i][0];
			tt[i][1] = (tt[i][0] + 10) * mm[i][1];
			for (int j = i - 1; j >= 0; --j) {
				int temp = tt[j][1] + (tt[i][0] - tt[j][0] + 10) * mm[i][1];
				if (temp < tt[i][1]) {
					tt[i][1] = temp;
				}
			}
		}
		cout << tt[num - 1][1] << endl;
	}
	return 0;
}
