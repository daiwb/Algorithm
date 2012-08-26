//ac

/**
 * suppose N has d digits and it P(N) divides N
 * since the product of these d digits divide N, the product of the first d-1 digits
 * divide N (just ignore the units digit), suppose further that P(N+1) divides N+1
 * divides. then the first d-1 digits of P(N+1) divide N+1 (same as for N).
 * since P(N) != 0 the units digit of N cannot be 9, hence N and N+1 have the same
 * number of digits, and the first d-1 digits of N are equal to the first d-1 digits
 * of N+1. let M be the product of the first d-1 digits of N (or N+1), we have shown
 * that M divides N, and M divides N+1. Hence M divides their difference, which happens
 * to be 1. since M divides 1, M=1.
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int K,count;
	scanf("%d", &K);
	if (K==1)
		printf("8\n");
	else
	{
		count = 1;
		if ((K-1)%3==0)
			count += 2;
		if ((K-1)%6==0)
			count++;
		printf("%d\n", count);
	}
	return 0;
}

