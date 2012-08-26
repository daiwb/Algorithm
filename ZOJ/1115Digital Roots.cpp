#include <stdio.h>

int main(void)
{
	int i,sum,b;
	char a[10000];
	gets(a);
	while(a[0]!='0'||a[1]!='\0'){
		sum=0;
		for(i=0;a[i]!='\0';i++)
			sum+=a[i]-'0';
		while(sum>=10){
			b=0;
			while(sum>=10){
				b+=sum%10;
				sum/=10;
			}
			sum+=b;
		}
		printf("%d\n",sum);
		gets(a);
	}
	return 0;
}