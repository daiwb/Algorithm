//zju 1028 Flip and Shift

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int kase;
	cin >> kase;
	while (kase --)
	{
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i ++)
		{
			cin >> a[i];
		}
		if (n % 2 == 1)
		{
			cout << "YES" << endl;
			delete []a;
			continue;
		}
		int odd = 0, even = 0;
		for (int i = 0; i < n; i += 2)
		{
			if(a[i] == 0) odd ++;
		}
		for (int i = 1; i < n; i += 2)
		{
			if(a[i] == 0) even ++;
		}
		if(abs(odd - even) <= 1) cout << "YES" << endl;
		else cout << "NO" << endl;
		delete []a;
	}
	return 0;
}
