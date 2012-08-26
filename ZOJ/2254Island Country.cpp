/*
 * zju 2254 Island Country
 * 00:00.57 3120k
 * 2004.08.10 by adai
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

#ifdef WIN32
#define for if(0);else for
#endif

//最长单调子序列,复杂度O(nlogn)
//注意最小序列覆盖和最长序列的对应关系,例如
//"define _cp(a,b) ((a)>(b))"求解最长严格递减序列,则
//"define _cp(a,b) (!((a)>(b)))"求解最小严格递减序列覆盖
//可更改元素类型和比较函数
#define MAXN 100005
#define _cp(a,b) ((a)<(b))
typedef int elem_t;

int subseq(int n,elem_t* a){
	int b[MAXN],i,l,r,m,ret=0;
	for (i=0;i<n;b[l]=i++,ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			if (_cp(a[b[m]],a[i]))
				l=m+1;
			else
				r=m-1;
	return ret;
}

class CLASS1 {
public:
	int value;
	int index;
};

int cmp(const void *t1,const void *t2) 
{ 
	CLASS1 *a,*b; 
	a=(CLASS1 *)t1; b=(CLASS1 *)t2; 
	if((*a).value-(*b).value>0) return 1;
	if((*a).value-(*b).value<0) return -1;	
	return 0;
} 

CLASS1 aa[100005], bb[100005];

int a[100005];
int b[100005];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &aa[i].value);
			aa[i].index = i;
		}
		for (int i = 0; i < n; i ++) {
			scanf("%d", &bb[i].value);
			bb[i].index = i;
		}

		qsort(aa, n, sizeof(CLASS1), cmp);
		qsort(bb, n, sizeof(CLASS1), cmp);

		for (int i = 0; i < n; i ++) {
			a[aa[i].index] = i;
		}

		for (int i = 0; i < n; i ++) {
			b[i] = a[bb[i].index];
		}

		int res;
		res = subseq(n, b);
		printf("%d\n", res);
	}
	return 0;
}
