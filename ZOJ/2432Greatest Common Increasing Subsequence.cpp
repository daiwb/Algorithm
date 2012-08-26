/**
 * ZOJ 2432 Greatest Common Increasing Subsequence
 */

//通过上次比赛那道题， 时间复杂度O(n^2 * logn)，空间 O(n^2)
/**
 * n为a的大小, m为b的大小
 * 结果在ans中
 * "define _cp(a,b) ((a)<(b))"求解最长严格递增序列
 */
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#define MAXN 500
#define _cp(a,b) ((a)<(b))
typedef int elem_t;
elem_t DP[MAXN][MAXN];

int num[MAXN], p[1<<20];
int comSubSeq(int n, elem_t *a, int m, elem_t *b, elem_t *ans){
    int i, j, l, r, k;

    DP[0][0] = 0;
    num[0] = (b[0] == a[0]);
    for(i = 1; i < m; i++) {
        num[i] = (b[i] == a[0]) || num[i-1];
        DP[i][0] = 0;
    }
    for(i = 1; i < n; i++){
        if(b[0] == a[i] && !num[0]) {
            num[0] = 1;
            DP[0][0] = i<<10;
        }

        for(j = 1; j < m; j++){
            for(k=((l=0)+(r=num[j-1]-1))>>1; l<=r; k=(l+r)>>1)
                if(_cp(a[DP[j-1][k]>>10], a[i]))
                    l=k+1;
                else
                    r=k-1;

            if(l < num[j-1] && i == (DP[j-1][l]>>10) ){
                if(l >= num[j]) DP[j][num[j]++] = DP[j-1][l];
                else DP[j][l] = _cp(a[DP[j][l]>>10],a[i]) ? DP[j][l] : DP[j-1][l];
            }
            if(b[j] == a[i]){
                for(k=((l=0)+(r=num[j]-1))>>1; l<=r; k=(l+r)>>1)
                    if(_cp(a[DP[j][k]>>10], a[i]))
                        l=k+1;
                    else
                        r=k-1;

                DP[j][l] = (i<<10) + j;
                num[j] += (l>=num[j]);
                p[DP[j][l]] = l ? DP[j][l-1] : -1;
            }
        }
    }

    for (k=DP[m-1][i=num[m-1]-1];i>=0;ans[i--]=a[k>>10],k=p[k]);
    return num[m-1];
}

int n, m, ret;
int a[MAXN], b[MAXN], ans[MAXN];

int Run() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
	ret = comSubSeq(n, a, m, b, ans);
	if (ret <= 0) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", ret);
	printf("%d", ans[0]);
	for (int i = 1; i < ret; ++i) printf(" %d", ans[i]);
	printf("\n");
	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 0; kk < kase; ++kk) {
		if (kk) printf("\n");
		Run();
	}
	return 0;
}