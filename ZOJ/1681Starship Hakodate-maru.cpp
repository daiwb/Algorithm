/*
ZJU 1681 Starship Hakodate-maru
00:00.02 444K
2004.07.04 By adai
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,num;
	int max1,max2;
	int i,j;
	while(cin>>n&&n!=0)
	{
		max1=pow(n,1.0/3.0);
		max1++;
		while(max1*max1*max1>n) max1--;
		num=0;
		for(i=0;i<=max1;i++)
		{
			int temp=n-i*i*i;
			max2=pow(temp*6,1.0/3.0);
			max2++;
			for(j=max2;j>=0;j--)
			{
				if(temp-j*(j+1)*(j+2)/6>=0) break;
			}
			if(i*i*i+j*(j+1)*(j+2)/6>num) num=i*i*i+j*(j+1)*(j+2)/6;
		}
		cout<<num<<endl;
	}
	return 0;
}