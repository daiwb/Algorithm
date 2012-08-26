#include <iostream>
#include <string>

using namespace std;

int main(void){
    int t,i,count1,count2;
    char op[10];
    char cur[75];
    char ba[105][75],fo[105][75];
    cin>>t;
    for(i=0;i<t;i++){
        if(i) cout<<endl;
        count1=count2=0;
        strcpy(cur,"http://www.acm.org/");
        while(cin>>op){
            if(strcmp(op,"VISIT")==0){
                strcpy(ba[++count1],cur);
                cin>>cur;
                cout<<cur<<endl;
                count2=0;
            }
            else if(strcmp(op,"BACK")==0){
                if(count1==0) cout<<"Ignored"<<endl;
                else{
                    strcpy(fo[++count2],cur);
                    strcpy(cur,ba[count1--]);
                    cout<<cur<<endl;
                }
            }
            else if(strcmp(op,"FORWARD")==0){
                if(count2==0) cout<<"Ignored"<<endl;
                else{
                    strcpy(ba[++count1],cur);
                    strcpy(cur,fo[count2--]);
                    cout<<cur<<endl;
                }
            }
            else break;
        }
    }
    return 0;
}
                    
                
            
            
            
        
    
