#include <stdio.h>
int main(void)
{
	int n,i,j,num=0;
	int pa[20]={0},pb[20]={0},a[20],b[20];
	char ca[42],cb[42];
	for(j=0;;j++){
		scanf("%d",&n);
		getchar();
		if(n==0) break;
		num++;
		gets(ca);
		gets(cb);
		for(i=0;i<n;i++){
			a[i]=ca[i*2]-48;
			b[i]=cb[i*2]-48;
			}
		for(i=0;i<n;i++){
			if(a[i]-b[i]==1||a[i]-b[i]==-1){
				if(a[i]==1||b[i]==1){
					if(a[i]==1) pa[j]+=6;
					if(b[i]==1) pb[j]+=6;
					}
				else{
					if(a[i]>b[i]) pb[j]+=a[i]+b[i];
					if(a[i]<b[i]) pa[j]+=a[i]+b[i];
					}
				}
			else{
				if(a[i]>b[i]) pa[j]+=a[i];
				if(a[i]<b[i]) pb[j]+=b[i];
				}
			}
		}
	for(i=0;i<num;){
		printf("A has %d points. B has %d points.\n",pa[i],pb[i]);
		i++;
		if(i<num) printf("\n");
		}
}