/*
 * ZJU 1219 Pizza Anyone?
 * 00:00.10 844k
 * 2005.02.03 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

int num = 0, pizza;
int constraint[16][16];
int mm[16];

int main()
{
	for(int i = 0; i < 16; i++)
		mm[i] = 1 << (15 - i);
	memset(constraint, 0, sizeof(constraint));
	char input[100];
	while (cin >> input)
	{
		if (strcmp(input, ".") == 0)
		{
			int satisfied;
			for(pizza = 0; pizza <= 0xffff; pizza++)
			{
				satisfied = 1;
				for(int i = 0; i < num; i++)
				{
					int ok = 0;
					for(int j = 0; j < 16; j++)
					{
						if (constraint[i][j] == 1)
						{
							if (pizza & mm[j])
							{
								ok = 1;
								break;
							}
						}
						else if (constraint[i][j] == -1)
						{
							if ((pizza & mm[j]) == 0)
							{
								ok = 1;
								break;
							}
						}
					}
					if (!ok)
					{
						satisfied = 0;
						break;
					}
				}
				if (satisfied)
				{
					cout << "Toppings: ";
					for(int i = 0; i < 16; i++)
						if (pizza & mm[i])
							cout << char(i + 'A');
					cout << endl;
					break;
				}
			}
			if (!satisfied) cout << "No pizza can satisfy these requests." << endl;
			num = 0;
			memset(constraint, 0, sizeof(constraint));
		}
		else
		{
			for(int i = 0; ; i += 2)
			{
				if (input[i] == ';')
				{
					num++;
					break;
				}
				else
				{
					if (input[i] == '+')
						constraint[num][input[i + 1] - 'A'] = 1;
					else
						constraint[num][input[i + 1] - 'A'] = -1;
				}
			}
		}
	}
	return 0;
}
