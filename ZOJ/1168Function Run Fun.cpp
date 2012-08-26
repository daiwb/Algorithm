/*ZJU 1168 Function Run Fun
2004.04.28 By adai
00:00.29 472K*/

#include <iostream>
using namespace std;

int main(){
	long long w[21][21][21]={0};
	long a,b,c;
	for(a=0;a<=20;a++){
		for(b=0;b<=20;b++){
			w[0][a][b]=w[a][0][b]=w[a][b][0]=1;
		}
	}
	for(a=1;a<=20;a++){
		for(b=1;b<=20;b++){
			for(c=1;c<=20;c++){
				if(a<b&&b<c) w[a][b][c]=w[a][b][c-1]+w[a][b-1][c-1]-w[a][b-1][c];
				else w[a][b][c]=w[a-1][b][c]+w[a-1][b-1][c]+w[a-1][b][c-1]-w[a-1][b-1][c-1];
			}
		}
	}
	int i,j,k;
	long long ans;
	while (scanf("%d %d %d", &i, &j, &k) != EOF) {
		if(i==-1&&j==-1&&k==-1) break;
		printf("w(%d, %d, %d) = ", i, j, k);
		if(i<=0||j<=0||k<=0) ans=1;
		else if(i>20||j>20||k>20) ans=w[20][20][20];
		else ans=w[i][j][k];
		printf("%lld\n", ans);
	}
	return 0;
}
