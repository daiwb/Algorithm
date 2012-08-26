/*
zju 1850 Factovisors
00:00.03 444k
*/

#include <iostream>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if (0); else for
#endif

int prime(int m){
	long i,p;
	p=(long)sqrt((double)m);
	for(i=2;i<=p;i++) 
	{ 
		if(!(m%i)) return 0;
	}
	return 1; 

}

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int main()
{
	int n, m;
	int sign = 1;
	while (1)
	{
		cin >> n >> m;
		if (cin.fail()) break;
		
		int k = m;

		if (m == 0)
		{
			sign = 0;
			goto out;
		}
		if (n == 0)
		{
			sign = 0;
			goto out;
		}
		
		if (m > n && prime(m))
		{
			sign = 0;
			goto out;
		}

		if (m <= n)
		{
			sign = 1;
			goto out;
		}

		for (int i = n; i >= 2; i --)
		{
			int j = gcd(i, m);
			if (j != 0)
			{
				m /= j;
			}
			if (m == 1 || m < i)
			{
				sign = 1;
				goto out;
			}
		}
		if (m == 1) sign = 1;
		else sign = 0;

out:
		if (sign)
		{
			cout << k << " divides " << n << "!" << endl;
		}
		else cout << k << " does not divide " << n << "!" << endl;
	}
	return 0;
}
