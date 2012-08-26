#include <iostream>
using namespace std;

int main(void)
{
	int s,d,i;
	while(scanf("%d %d", &s, &d) &&!(s==0&&d==0)){
		for(i=1;i<=60;i++){
			s=(s+s*d)%60;
			if(s==0) break;
		}
		if(i==61) printf("Impossible\n");
		else printf("%d\n", i);
	}
	return 0;
}
