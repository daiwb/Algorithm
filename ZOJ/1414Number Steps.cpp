#include<stdio.h>
int main(void)
{
	int n,i,j,x[20]={0},y[20]={0};
	char ch[12];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		gets(ch);
		for(j=0;ch[j]!=' ';j++)
			x[i]=x[i]*10+ch[j]-48;
		for(++j;ch[j]!='\0';j++)
			y[i]=y[i]*10+ch[j]-48;
		}
	for(i=0;i<n;i++){
		if(x[i]==y[i]){
			if(x[i]%2==0){
				x[i]=x[i]/2;
				printf("%d\n",4*x[i]);
				}
			else{
				x[i]=(x[i]+1)/2;
				printf("%d\n",4*x[i]-3);
				}
			}
		else if(y[i]==x[i]-2){
				if(x[i]%2==0){
					x[i]=x[i]/2;
					printf("%d\n",4*x[i]-2);
					}
				else{
					x[i]=(x[i]-1)/2;
					printf("%d\n",4*x[i]-1);
					}
				}
			 else printf("No Number\n");
		}
}


		
