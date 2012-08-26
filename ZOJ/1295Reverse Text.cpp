#include <stdio.h>
#include <string.h>

int main(void){
	int n,i,j,len;
	char str[100];
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++){
		gets(str);
		len=strlen(str);
		for(j=0;j<len;j++) printf("%c",str[len-1-j]);
		printf("\n");
	}
	return 0;
}
