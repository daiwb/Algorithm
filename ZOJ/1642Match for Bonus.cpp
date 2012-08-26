#include <iostream>
#include <cstdio>
using namespace std;

#define MAX	2200

int N;
int val[128];
char a[MAX], b[MAX];
int score[MAX][MAX];

void Run()
{
	int lena = strlen(a), lenb = strlen(b);
	for (int i = 0; i <= lena; i ++)
	for (int j = 0; j <= lenb; j ++)
		score[i][j] = -2000000000;
	score[0][0] = 0;

	for (int i = 0; i <= lena; i ++)
	for (int j = 0; j <= lenb; j ++) {
		if (i < lena)
		if (score[i][j] > score[i + 1][j])
			score[i + 1][j] = score[i][j];
		if (j < lenb)
		if (score[i][j] > score[i][j + 1])
			score[i][j + 1] = score[i][j];
		if (i < lena && j < lenb)
		if (a[i] == b[j])
		if (score[i][j] + val[a[i]] > score[i + 1][j + 1])
			score[i + 1][j + 1] = score[i][j] + val[a[i]];
	}

	printf("%ld\n", score[lena][lenb]);
}

int main()
{
	char temp[100];
	while (scanf("%ld", &N) != EOF) {
		for (int i = 0; i < N; i ++) {
			scanf("%s", temp);
			scanf("%ld", &val[temp[0]]);
		}
		scanf("%s%s", a, b);
		Run();
	}
	return 0;
}
