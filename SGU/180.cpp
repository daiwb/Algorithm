//ac

#include <iostream>
#include <string>
using namespace std;

#define MAXN 65537
#define _cp(a,b) ((a)<=(b))
typedef int elem_t;
elem_t _tmp[MAXN];

long long inv(int n,elem_t* a){
	int l=n>>1,r=n-l,i,j;
	long long ret=(r>1?(inv(l,a)+inv(r,a+l)):0);
	for (i=j=0;i<=l;_tmp[i+j]=a[i],i++)
		for (ret+=j;j<r&&(i==l||!_cp(a[i],a[l+j]));_tmp[i+j]=a[l+j],j++);
	memcpy(a,_tmp,sizeof(elem_t)*n);
	return ret;
}

int a[MAXN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	long long ret = inv(n, a);
	printf("%lld\n", ret);
	return 0;
}

