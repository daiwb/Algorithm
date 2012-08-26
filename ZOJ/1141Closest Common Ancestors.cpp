/*
ZJU 1141 Closest Common Ancestors
2004.06.30 By adai
00:01.41 444K
*/
#include <iostream>
using namespace std;

int main()
{
	int n,i,j;
	while(cin>>n)
	{
		int* parent=new int[n+1];
		int* count=new int[n+1];
		int* sign=new int[n+1];
		for(i=1;i<=n;i++)
		{
			parent[i]=count[i]=0;
		}
		int vertex,successor,number;
		char c;
		for(i=0;i<n;i++)
		{
			cin>>vertex>>c>>c>>number>>c;
			for(j=0;j<number;j++)
			{
				cin>>successor;
				parent[successor]=vertex;
			}
		}
		cin>>number;
		int u,v;
		for(i=0;i<number;i++)
		{
			for(j=1;j<=n;j++)
			{
				sign[j]=0;
			}
			cin>>c>>u>>c>>v>>c;
			while(parent[u])
			{
				sign[u]=1;
				u=parent[u];
			}
			sign[u]=1;
			while(parent[v])
			{
				if(sign[v]) break;
				v=parent[v];
			}
			count[v]++;
		}
		for(i=1;i<=n;i++)
		{
			if(count[i])
			{
				cout<<i<<":"<<count[i]<<endl;
			}
		}
		delete []parent;
		delete []count;
		delete []sign;
	}
	return 0;
}