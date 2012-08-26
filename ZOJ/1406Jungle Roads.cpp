/*
 * ZJU 1406 Jungle Roads
 * 00:00.00 840k
 * 2005.03.16 by adai
 */

#include <iostream>
#include <string>
using namespace std;

//无向图最小生成树,prim算法,邻接阵形式,复杂度O(n^2)
//返回最小生成树的长度,传入图的大小n和邻接阵mat,不相邻点边权inf
//可更改边权的类型,pre[]返回树的构造,用父结点表示,根节点(第一个)pre值为-1
//必须保证图的连通的!
#define MAXN 26
#define inf 1000000
typedef int elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre)
{
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

int n, ret;
int mat[26][26];
int pre[26];

int main()
{
	while (cin >> n && n)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				mat[i][j] = inf;
			}
		}

		for (int i = 0; i < n - 1; ++i)
		{
			char c;
			cin >> c;
			int cc, cost;
			cin >> cc;
			while (cc--)
			{
				cin >> c >> cost;
				mat[i][c - 'A'] = mat[c - 'A'][i] = cost;
			}
		}

		ret = prim(n, mat, pre);
		cout << ret << endl;
	}
	return 0;
}
