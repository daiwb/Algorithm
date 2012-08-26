/*
ZJU 1657 Goldbach's Conjecture
2004.07.02 By adai
00:00.02 668K
*/

#include <iostream>
#include <cmath>
using namespace std;

//用质数表判定质数,先调用initprime
int plist[10000],pcount=0;
int list[50000];

int prime(int n){
	int i;
	if ((n!=2&&!(n%2))||(n!=3&&!(n%3))||(n!=5&&!(n%5))||(n!=7&&!(n%7)))
		return 0;
	for (i=0;plist[i]*plist[i]<=n;i++)
		if (!(n%plist[i]))
			return 0;
		return n>1;
}

void initprime(){
	int i;
	for(i=0;i<50000;i++)
	{
		list[i]=0;
	}
	//memset(list,0,sizeof(list));
	for (plist[pcount++]=2,i=3;i<50000;i++)
		if (prime(i))
		{
			plist[pcount++]=i;
			list[i]=1;
		}
}

int main()
{
	int i,n,num,end;
	while(cin>>n&&n!=0)
	{
		if(n==4)
		{
			cout<<1<<endl;
			continue;
		}
		num=0;
		end=n/2;
		if(end%2==0) end--;
		for(i=1;plist[i]<=end;i++)
		{
			if(list[n-plist[i]]==1)
			{
				num++;
			}
		}
		cout<<num<<endl;
	}
}