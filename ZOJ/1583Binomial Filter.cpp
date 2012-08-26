/*
ZJU 1583 Binomial Filter
2004.06.30 By adai
00:00.28 2400K
*/
#include <iostream>
using namespace std;

int main(){
	int n,kase(1);
	int i,j,p,q;
	int **a;
	int **b;
	a=new int*[500];
	b=new int*[500];
	for(i=0;i<500;i++){
		a[i]=new int[500];
		b[i]=new int[500];
	}
	int B[3][3]={1,2,1,2,4,2,1,2,1};
	while(scanf("%d",&n)&&n!=0){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
			    scanf("%d",&a[i][j]);
			}
		}
		for(j=0;j<n;j++){
			b[0][j]=a[0][j];
			b[n-1][j]=a[n-1][j];
		}
		for(i=1;i<n-1;i++){
			b[i][0]=a[i][0];
			b[i][n-1]=a[i][n-1];
		}
		for(i=1;i<n-1;i++){
			for(j=1;j<n-1;j++){
				int temp(0);
				for(p=0;p<3;p++){
					for(q=0;q<3;q++){
						temp+=a[i+p-1][j+q-1]*B[p][q];
					}
				}
				temp/=16;
				b[i][j]=temp;
			}
		}
		printf("Case %d:\n",kase++);
		for(i=0;i<n;i++){
		    printf("%d",b[i][0]);
			for(j=1;j<n;j++) printf(" %d",b[i][j]);
			printf("\n");
		}
	}
	return 0;
}