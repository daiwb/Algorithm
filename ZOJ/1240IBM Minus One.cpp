#include <stdio.h>
int main(void)
{
	int n,i,j;
	char ch;
	char s[100][51];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%s",s[i]);
	for(i=0;;){
		printf("String #%d\n",i+1);
		for(j=0;;j++){
			if(s[i][j]=='\0') break;
			ch=s[i][j]+1;
			if(ch==91) ch=65;
			printf("%c",ch);
			}
		printf("\n\n");
		i++;
		if(i==n) break;
		}
}

