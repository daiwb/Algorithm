/*
ZJU 1652 Count the Regions
2004.07.03 By adai
00:00.03 432K
*/

#include <iostream>
using namespace std;

int main()
{
	int n,region;
	while(cin>>n)
	{
		region=(9*n*n-7*n)/2+1;
		cout<<region<<endl;
	}
	return 0;
}