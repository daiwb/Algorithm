#include <stdio.h>
#include <string.h>

int main(void){
	int i;
	char a[15],b[205];
	while(1){
		gets(a);
		if(strcmp(a,"ENDOFINPUT")==0) break;
		gets(b);
		gets(a);
		for(i=0;b[i]!='\0';i++){
			if(b[i]>=65&&b[i]<=90){
				b[i]-=5;
				if(b[i]<65) b[i]+=26;
			}
			printf("%c",b[i]);
		}
		printf("\n");
	}
	return 0;
}
