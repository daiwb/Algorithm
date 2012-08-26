#include <stdio.h>

int main(void){
	int n,m,i,j,t,s;
	char str[100],temp[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(i) printf("\n");
		scanf("%d",&m);
		getchar();
		for(j=0;j<m;j++){
			gets(str);
			s=0;
			for(t=0;;t++){
				if(str[t]=='\0'){
					for(s--;s>=0;s--)
						printf("%c",temp[s]);
					printf("\n");
					break;
				}
				else if(str[t]==' '){
					for(s--;s>=0;s--)
						printf("%c",temp[s]);
					printf(" ");
					s=0;
				}
				else temp[s++]=str[t];
			}
		}
	}
	return 0;
}
