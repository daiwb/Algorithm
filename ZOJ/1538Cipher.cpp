//00:00.12 672k

#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
int num[61100];

void Run ()
{
	int start = 0;
	for (int i = 0; i < N; i ++) {
 		start = (start + num[start]) % N;
	}
	printf("%d\n", num[start]);
}

int main()
{
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i ++)
		    scanf("%d", &num[i]);
		Run ();
	}
	return 0;
}
