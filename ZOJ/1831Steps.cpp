/*
ZJU 1831 Steps
2004.07.02 By adai
00:00.28 436K
*/

#include <iostream>
using namespace std;

int main()
{
	int x,y,step,num,t;
	while(cin>>x>>y)
	{
		step=y-x;
		num=0;
		for(t=1;;t++)
		{
			if(step-2*t<0)
			{
				if(step-t>0)
				{
					num++;
					step-=t;
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				step-=2*t;
				num+=2;
			}
		}
		for(;t>=1;t--)
		{
			num+=step/t;
			step%=t;
			if(step==0) break;
		}
		cout<<num<<endl;
	}
	return 0;
}