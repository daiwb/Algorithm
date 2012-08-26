/*
 * ZJU 1339 Machined Surfaces
 * 00:00.00 840k
 * 2005.02.03 by adai
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n) {
		vector<int> v;
		char in[26];
		cin.getline(in, 100);
		int mm = 23;
		for(int i = 0; i < n; i++)
		{
			cin.getline(in, 100);
			int count = 0;
			for(int j = 0; j < 25; j++)
			{
				if (in[j] != 'X') count++;
			}
			v.push_back(count);
			if (count < mm) mm = count;
		}
		int ret = 0;
		for(int i = 0; i < n; i++)
			ret += v[i] - mm;
		cout << ret << endl;
	}
	return 0;
}
