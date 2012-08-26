#include <stdio.h>
int main(void)
{
	int d,n,i,j,o[10],p[10];
	scanf("%d",&d);
	getchar();
	for(i=0;i<d;i++){
		scanf("%d",&n);
		getchar();
		for(j=0;;n/=2,j++)
			if(n%2!=0) break;
		p[i]=j;
		o[i]=n;
		}
	for(i=0;i<d;i++)
		printf("%d %d\n",o[i],p[i]);
}


