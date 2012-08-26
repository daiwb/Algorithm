/*ZJU 1976 Paths on a Grid
2004.04.27 By adai
00:00.00 432K*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(void){
    unsigned long i,n,m;
    double result;
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        result=1;
		n+=m;
		m=m<(n-m)?m:(n-m);
        for(i=1;i<=m;i++){
            result*=(double)(n-m+i)/(double)i;
        }
		cout<<setiosflags(ios::fixed)<<setprecision(0)<<result<<endl;
    }
    return 0;
}
        
