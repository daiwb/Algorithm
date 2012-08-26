/*ZJU 2058 The Archaeologist's Trouble II
2003.12.20 By adai
00:00.01 448K*/

#include <iostream>

using namespace std;

int main(void){
    long n,i,j,t,max,min;
    char a[105][105];
    while(cin>>n){
        if(n<0) break;
        for(i=0;i<n;i++) cin>>a[i];
        max=min=0;
        for(i=0;i<n;i++){
            if(i%2==1){
                max+=(i+1)/2;
                min+=(i+1)/2;
                continue;
            }
            for(j=0;j<=i;j++) if(a[i][j]=='*') break;
            for(t=0;t<=i;t++) if(a[i][t]=='@') break;
            if(j==i+1&&t==i+1){
                max+=(i+2)/2;
                min+=i/2;
            }
            else if(t==i+1){
                if(j%2==0){
                    max+=(i+1)/2;
                    min+=(i+1)/2;
                }
                else{
                    max+=(i+2)/2;
                    min+=(i+2)/2;
                }
            }
            else{
                if(t%2==1){
                    max+=(i+1)/2;
                    min+=(i+1)/2;
                }
                else{
                    max+=(i+2)/2;
                    min+=(i+2)/2;
                }
            }
        }
        cout<<max<<" "<<min<<endl;
    }
    return 0;
}
                        
                    
        
