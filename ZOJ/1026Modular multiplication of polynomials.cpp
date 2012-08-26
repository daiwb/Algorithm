//2003.07.27 by adai

#include <iostream>

using namespace std;

int main(void){
    int t,fn,gn,hn,n,i,j,temp;
    cin>>t;
    while(t--){
        cin>>fn;
        int* f=new int[fn];
        for(i=fn-1;i>=0;i--) cin>>f[i];
        cin>>gn;
        int* g=new int[gn];
        for(i=gn-1;i>=0;i--) cin>>g[i];
        cin>>hn;
        int* h=new int[hn];
        for(i=hn-1;i>=0;i--) cin>>h[i];
        n=(fn-1)+(gn-1)+1;
        int* out=new int[n];
        for(i=0;i<n;i++) out[i]=0;
        for(i=0;i<fn;i++){
            for(j=0;j<gn;j++){
                out[i+j]=(out[i+j]+f[i]*g[j])%2;
            }
        }
        for(i=n-1;;i--){
            while(out[i]==0&&i>=0){
                i--;
                if(i<0){
                    i=0;
                    break;
                }
            }
            if(i<hn-1){
                cout<<i+1;
                for(;i>=0;i--) cout<<" "<<out[i];
                cout<<endl;
                break;
            }
            temp=i-(hn-1);
            for(j=hn-1;j>=0;j--){
                out[j+temp]=(out[j+temp]+h[j])%2;
            }
        }
        delete []f;
        delete []g;
        delete []h;
        delete []out;
    }
    return 0;
}
        
        
        
        
