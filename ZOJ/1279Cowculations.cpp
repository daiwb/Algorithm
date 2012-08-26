/*
 * ZJU 1279 Cowculations
 * 00:00.00 840k
 * 2005.02.02 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

int ctoi(char c)
{
	if (c == 'V') return 0;
	if (c == 'U') return 1;
	if (c == 'C') return 2;
	return 3;
}

char itoc(int i)
{
	if (i == 0) return 'V';
	if (i == 1) return 'U';
	if (i == 2) return 'C';
	return 'D';
}

int main()
{
	cout << "COWCULATIONS OUTPUT" << endl;

	int kase;
	cin >> kase;
	while (kase--)
	{
		char num1[9], num2[9], input[9];
		cin >> input;
		for(int i = 0; i < 5; i ++)
			num1[i] = input[4 - i];
		cin >> input;
		for(int i = 0; i < 5; i ++)
			num2[i] = input[4 - i];
		int len = 5;

		char op;
		for(int ii = 0; ii < 3; ii++)
		{
			cin >> op;
			if (op == 'A')
			{
				int a, b, carry = 0;
				for(int i = 0; i < 5; i++)
				{
					a = ctoi(num1[i]);
					b = ctoi(num2[i]);
					num2[i] = itoc((a + b + carry) % 4);
					if (a + b + carry >= 4) carry = 1;
					else carry = 0;
				}
				for(int i = 5; i < len; i++)
				{
					b = ctoi(num2[i]);
					num2[i] = itoc((b + carry) % 4);
					if (b + carry >= 4) carry = 1;
					else carry = 0;
				}
				if (carry) num2[len++] = 'U';
			}
			else if (op == 'R')
			{
				for(int i = 1; i < len; i++)
					num2[i - 1] = num2[i];
				num2[len - 1] = 'V';
			}
			else if (op == 'L')
			{
				for(int i = len - 1; i >= 0; i--)
					num2[i + 1] = num2[i];
				num2[0] = 'V';
				len++;
			}
		}
		for(int i = len; i < 8; i++) num2[i] = 'V';
		num2[8] = '\0';
		char result[9];
		cin >> input;
		for(int i = 0; i < 8; i++) result[i] = input[7 - i];
		result[8] = '\0';
		if (strcmp(num2, result) == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	cout << "END OF OUTPUT" << endl;
	return 0;
}
