#include <iostream>

using namespace std;

int main(void){
    int t,n,i,j;
    cin>>t;
    while(t--){
        cin>>n;
        int p,sum=0,count=0;
        int* num=new int[2*n];
        for(i=0;i<n;i++){
                cin>>p;
                for(j=0;j<p-sum;j++) num[count++]=1;
                num[count++]=0;
                sum=p;
        }
        int total,a;
        for(i=0;i<2*n;i++){
                while(num[i]!=0) i++;
                total=1;
                a=1;
                for(j=i-1;;j--){
                        if(num[j]==0){
                                total++;
                                a++;
                        }
                        else a--;
                        if(a==0) break;
                }
                cout<<total;
                if(i!=2*n-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;    
}
                
                
                                
                
                
        
        
        
        
