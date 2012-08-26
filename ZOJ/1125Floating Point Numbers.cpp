#include<stdio.h>
#include<math.h>

int main(void){
	char num[16];
	double value;
	int i,man,judge,count;
	printf("Program 6 by team X\n");
	while(gets(num)){
		judge=count=0;
		man=0;
		value=1;
		for(i=7;i>=1;i--)
			man+=(num[i]-'0')*(int)pow(2,7-i);
		if(man==0) judge=1;
		man-=63;
		for(i=8;i<16;i++)
			value+=(num[i]-'0')*pow(2,7-i);
		if(value==1&&judge==1){
			printf(" 0.000000e+000\n");
			continue;
		}
		if(num[0]=='1')	printf("-");
		else printf(" ");
		if(man>0){
			for(i=1;i<=man;i++){
				value*=2;
				if(value>=10){
					value/=10;
					count++;
				}
			}
		}
		else{
			man*=-1;
			for(i=1;i<=man;i++){
				value/=2;
				if(value<1){
					value*=10;
					count--;
				}
			}
		}
		printf("%.6fe",value);
		if(count==0) printf("+000\n");
		else{
			if(count<0){
				printf("-");
				count*=-1;
			}
			else printf("+");
			if(count<10) printf("00%d\n",count);
			else if(count<100) printf("0%d\n",count);
			else printf("%d\n",count);
		}
	}
	printf("End of program 6 by team X\n");
	return 0;
}









