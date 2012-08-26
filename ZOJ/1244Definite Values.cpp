#include <iostream>

using namespace std;

int main(void){
    int t,i,j,count=1;
    char v1,op,v2;
    while(cin>>t&&t!=0){
        int num[26]={0};
        num[0]=1;
        while(t--){
            cin>>v1>>op>>v2;
            if(num[v2-97]==1) num[v1-97]=1;
            else num[v1-97]=0;
        }
        j=0;
        cout<<"Program #"<<count++<<endl;
        for(i=0;i<26;i++){
            if(num[i]==1){
                cout<<char(i+97)<<" ";
                j=1;
            }
        }
        if(j==0) cout<<"none";
        cout<<endl<<endl;
    }
    return 0;
}
        
            
        
        
            
