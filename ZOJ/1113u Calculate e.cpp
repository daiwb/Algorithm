#include <stdio.h>
int main(void)
{
	int n;
	double e=2.5,i=2;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n1 2\n2 2.5\n");
	for(n=3;n<10;n++){
		i*=n;
		e+=1/i;
		printf("%d %.9f\n",n,e);
		}
}


