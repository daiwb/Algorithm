//ac

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 1000000
#define _cp(a,b) ((a)<(b))

struct people {
	public:
		int s;
		int b;
		int idx;
		bool operator < (const people &r) const {
			if (s != r.s) return s < r.s;
			return b > r.b;
		}
};

vector<people> mm;
int n;
vector<int> ans;

int cmp(people a, people b) {
	return b.b > a.b;
}

int b[MAXN], p[MAXN];

int subseq(int n){
	int i,l,r,m,ret=0;
	for (i=0;i<n;p[b[l]=i++]=b[l-1],ret+=(l>ret))
		for (m=((l=1)+(r=ret))>>1;l<=r;m=(l+r)>>1)
			//if (_cp(a[b[m]],a[i]))
			//	l=m+1;
			if (cmp(mm[b[m]], mm[i]))
				l=m+1;
			else
				r=m-1;
	for (m=b[i=ret];i;ans[--i]=mm[m].idx,m=p[m]);
	return ret;
}

int main() {
	scanf("%d", &n);
	mm.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &mm[i].s, &mm[i].b);
		mm[i].idx = i;
	}
	sort(mm.begin(), mm.end());
	int ret = subseq(n);
	printf("%d\n", ret);
	for (int i = 0; i < ret; ++i) {
		if (i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
	return 0;
}

