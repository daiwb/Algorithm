#include <iostream>
#include <string>

using namespace std;

class matrix{
public:
    int a;
    int b;
    static int t;
    static int num;
	matrix(){}
    matrix(int i,int j){
        a=i;
        b=j;
    }
    ~matrix(){}
    matrix operator * (matrix m){
        if(b!=m.a) t=1;
        num+=a*b*m.b;
        return matrix(a,m.b);
    }
};

int matrix::t=0;
int matrix::num=0;

int num,t;
matrix mat[26];

matrix mul(char chain[1000000],int m,int n){
    if(m==n) return mat[chain[m]-'A'];
    int sum=0,i;
    if(chain[m]=='('){
        for(i=m+1;;i++){
            if(chain[i]=='(') sum++;
            else if(chain[i]==')'){
                if(sum==0) break;
                else sum--;
            }
        }
        if(chain[i+1]=='(') return mul(chain,m+1,i-1)*mul(chain,i+2,n-1);
        else return mul(chain,m+1,i-1)*mul(chain,n,n);
    }
    else{
        if(chain[m+1]=='(') return mul(chain,m,m)*mul(chain,m+2,n-1);
        else return mul(chain,m,m)*mul(chain,n,n);
    }
}
    
int main(void){
    int n,i,len;
    char ch;
    char chain[100000];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ch;
        cin>>mat[ch-'A'].a;
        cin>>mat[ch-'A'].b;
    }
    while(cin>>chain){
        len=strlen(chain);
        if(len==1){
            cout<<"0"<<endl;
            continue;
        }
        matrix::num=0;
        matrix::t=0;
        mul(chain,1,len-2);
        if(matrix::t==1) cout<<"error"<<endl;
        else cout<<matrix::num<<endl;
    }
    return 0;
}
        
        
