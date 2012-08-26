#include <stdio.h>
int main(void)
{
	float money[12];
	float sum=0.00,avg;
	int i;
	for(i=0;i<12;i++){
		scanf("%f",&money[i]);
		sum+=money[i];
		}
	avg=sum/12;
	printf("$%.2f\n",avg);
}
