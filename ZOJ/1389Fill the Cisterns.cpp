/*
ZJU 1389 Fill the Cisterns
00:07.44 4316K
2004.07.13 by adai
*/

#include <stdio.h>

class cistern
{
public:
	int b;
	int h;
	int w;
	int d;
	int s;
};

int main()
{
	int kase,n,maxh,v;
	int i,j;
	scanf("%d",&kase);
	while(kase--)
	{
		scanf("%d",&n);
		cistern* cis=new cistern[n];
		maxh=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&cis[i].b,&cis[i].h,&cis[i].w,&cis[i].d);
			cis[i].s=cis[i].w*cis[i].d;
			cis[i].h+=cis[i].b;
			if(cis[i].h>maxh) maxh=cis[i].h;
		}
		scanf("%d",&v);
		int* a=new int[maxh];
		for(i=0;i<maxh;i++) a[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=cis[i].b;j<cis[i].h;j++) a[j]+=cis[i].s;
		}
		//for(i=0;i<maxh;i++) printf("a[%d]=%d\n",i,a[i]);
		int lv=v;
		int sign=0;
		for(i=0;i<maxh;i++)
		{
			lv-=a[i];
			if(lv<=0)
			{
				lv+=a[i];
				sign=1;
				break;
			}
		}
		if(sign==0)
		{
			printf("OVERFLOW\n");
			delete []cis;
			delete []a;
			continue;
		}
		double height=i;
		int s(0);
		for(j=0;j<n;j++)
		{
			if(i>=cis[j].b&&i<cis[j].h) s+=cis[j].s;
		}
		height+=(double)lv/s;
		printf("%.2lf\n",height);
		delete []cis;
		delete []a;
	}
	return 0;
}
