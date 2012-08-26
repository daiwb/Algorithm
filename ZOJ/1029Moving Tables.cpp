/*ZJU 1029 Moving Tables
2004.06.28 By adai
00:00.00 436K*/

#include <iostream>
using namespace std;

int main()
{
	int T,N;
	int table[200];
	int i;
	cin>>T;
	while(T--)
	{
		cin>>N;
		int s,t;
		for(i=0;i<200;i++) table[i]=0;
		while(N--)
		{
			cin>>s>>t;
			s=(s-1)/2;
			t=(t-1)/2;
			if(s>t)
			{
				int temp=s;
				s=t;
				t=temp;
			}
			for(i=s;i<=t;i++)
			{
				table[i]++;
			}
		}
		int minTime(-1);
		for(i=0;i<200;i++)
		{
			if(table[i]>minTime) minTime=table[i];
		}
		cout<<minTime*10<<endl;
	}
	return 0;
}