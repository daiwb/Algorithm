/*
 * ZJU 1272 Numerically Speaking
 * 00:00.00 844k
 * 2005.02.02 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 200

void add(int out[MAXN], int power[MAXN])
{
	int carry = 0;
	for(int i = 0; i < 50; i++)
	{
		int temp = out[i] + power[i] + carry;
		if (temp >= 10)
		{
			temp -= 10;
			carry = 1;
		}
		else carry = 0;
		out[i] = temp;
	}
}

void move(int a[MAXN], int count)
{
	int i = MAXN - 1;
	while (a[i] == 0) i--;
	while (i >= 0)
	{
		a[i + count] = a[i];
		i--;
	}
	for(int j = 0; j < count; j++) a[j] = 0;
}

int main()
{
	char in[MAXN];
	int out[MAXN];
	while (1)
	{
		cin >> in;
		if (strcmp(in, "*") == 0) break;
		int len = strlen(in);

		if (in[0] >= '0' && in[0] <= '9')
		{
			memset(out, 0, sizeof(out));
			int num = 0;
			int mm[MAXN], temp[MAXN];
			memset(mm, 0, sizeof(mm));
			memset(temp, 0, sizeof(temp));

			for(int i = 0; i < len; i++) mm[i] = in[len - 1 - i] - '0';
			int number[MAXN];
			memcpy(number, mm, sizeof(mm));

			while (1)
			{
				int ii = MAXN - 1;
				while (mm[ii] == 0) ii--;
				if (ii == 0)
				{
					out[num++] = mm[ii];
					break;
				}
				else if (ii == 1)
				{
					int aa = mm[1] * 10 + mm[0];
					if (aa <= 26) out[num++] = aa;
					else
					{
						out[num++] = aa % 26;
						out[num++] = aa / 26;
					}
					break;
				}
				else
				{
					int bb = mm[ii--];
					while (ii >= 0)
					{
						bb = bb * 10 + mm[ii];
						temp[ii] = bb / 26;
						bb %= 26;
						ii--;
					}
					out[num++] = bb;
					memcpy(mm, temp, sizeof(mm));
					memset(temp, 0, sizeof(temp));
				}
			}
			for(int i = num - 1; i >= 0; i--) cout << char(out[i] + 'a' - 1);
			for(int i = num + 1; i < 23; i++) cout << " ";
			int ii = MAXN - 1;
			while (number[ii] == 0) ii--;
			while (ii >= 0)
			{
				cout << number[ii];
				if (ii == 0) cout << endl;
				else if (ii % 3 == 0) cout << ",";
				ii--;
			}
		}
		else
		{
			memset(out, 0, sizeof(out));
			int power[MAXN];
			memset(power, 0, sizeof(power));
			power[0] = 1;
			for(int i = len - 1; i >= 0; i--)
			{
				int count = in[i] - 'a' + 1;
				for(int j = 0; j < count; j++) add(out, power);
				int tt[2][MAXN];
				memcpy(tt[0], power, sizeof(power));
				memcpy(tt[1], power, sizeof(power));
				move(tt[1], 1);
				memset(power, 0, sizeof(power));
				for(int j = 0; j < 6; j++) add(power, tt[0]);
				for(int j = 0; j < 2; j++) add(power, tt[1]);
			}
			cout << in;
			for(int i = len + 1; i < 23; i++) cout << " ";
			int ii = MAXN - 1;
			while (out[ii] == 0) ii--;
			while (ii >= 0)
			{
				cout << out[ii];
				if (!ii) cout << endl;
				else if (ii % 3 == 0) cout << ",";
				ii--;
			}
		}
	}
	return 0;
}
