#include <stdio.h>
int main(void)
{
	int n,u,d,i,sum,time[20]={0},temp;
	scanf("%d %d %d",&n,&u,&d);
	for(i=0;;i++){
		if(n==0) break;
		sum=0;
		for(;;){
			sum+=u;
			time[i]++;
			if(sum>=n) break;
			sum-=d;
			time[i]++;
			}
		scanf("%d %d %d",&n,&u,&d);
		}
	temp=i;
	for(i=0;i<temp;i++)
		printf("%d\n",time[i]);
}
