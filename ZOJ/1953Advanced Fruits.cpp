/*
ZJU 1953 Advanced Fruits
00:00.00 536K
*/

#include <stdio.h>
#include <string.h>

#define MAX 2000

char a[MAX],b[MAX];
int memo[MAX][MAX];

int scs (int i, int j)
{
	if (memo[i][j]<0)
    {
		if (a[i]==0)
			memo[i][j] = strlen(b+j);
		else if (b[j]==0)
			memo[i][j] = strlen(a+i);
		else if (a[i]==b[j])
			memo[i][j] = scs(i+1,j+1) + 1;
		else
			memo[i][j] = (scs(i+1,j) < scs(i,j+1)?scs(i+1,j):scs(i,j+1)) + 1;
		
    }
	return memo[i][j];
}

void solve_case()
{
	int i,j;
	int lena,lenb;
	lena=strlen(a);
	lenb=strlen(b);
	for (i=0; i<=lena; i++){
		for (j=0; j<=lenb; j++)
			memo[i][j] = -1;
	}
	scs(0,0);
	for (i=j=0;;)
	{
		if (a[i]==0)
		{
			printf("%s\n",b+j);
			break;
		}
		else if (b[j]==0)
		{
			printf("%s\n",a+i);
			break;
		}
		else if (a[i]==b[j])
		{
			putchar(a[i]);
			i++; j++;
		}
		else if (memo[i+1][j] <= memo[i][j+1])
		{
			putchar(a[i]);
			i++;
		}
		else
		{
			putchar(b[j]);
			j++;
		}
	}
}

int main()
{
	while(scanf("%s %s",a,b)!=EOF) solve_case();
	return 0;
}

