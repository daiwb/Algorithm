#include <iostream>
#include <string> 

using namespace std;

int main(void){
    cout<<"SLURPYS OUTPUT"<<endl;
    int IsSlump(char a[65],int m,int n);
    int IsSlimp(char a[65],int m,int n);
    int t;
    char a[65];
    cin>>t;
    while(t--){
        cin>>a;
        int m,n,i;//m代表slimp结束的位置,n代表slump结束的位置
        int c=1,c1,c2;
        n=strlen(a)-1;
        m=0;
        for(i=0;i<=n;i++){
            if(!(a[i]=='D'||a[i]=='E'||a[i]=='F'||a[i]=='G'
            ||a[i]=='A'||a[i]=='H'||a[i]=='B'||a[i]=='C')){
                c=0;
                break;
            }
        }
        if(c==0){
            cout<<"NO"<<endl;
            continue;
        }
        for(i=n;i>=0;i--){
            if(a[i]=='H'||a[i]=='C'){
                m=i;
                break;
            }
        }
        c1=IsSlump(a,m+1,n);
        c2=IsSlimp(a,0,m);
        c=c1&c2;
        if(c==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}

int IsSlump(char a[65],int m,int n){
    if(n-m<2) return 0;
    int i;
    if(!((a[m]=='D'||a[m]=='E')&&a[m+1]=='F')) return 0;
    for(i=m+2;;i++) if(a[i]!='F') break;
    if(a[i]=='G'){
        if(i==n) return 1;
        else return 0;
    }
    else return IsSlump(a,i,n);
}

int IsSlimp(char a[65],int m,int n){
    if(n-m<1) return 0;
    if(a[m]!='A') return 0;
    if(a[m+1]=='H'){
        if(m+1==n) return 1;
        else return 0;
    }
    if(a[m+1]=='B'){
        if(a[n]!='C') return 0;
        return IsSlimp(a,m+2,n-1);
    }
    if(a[n]!='C') return 0;
    return IsSlump(a,m+1,n-1);
}
    
        
         
        
                
        
