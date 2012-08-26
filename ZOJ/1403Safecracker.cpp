//ZJU 1403 Safecracker
//2003.09.27 BY adai
//00:00.05 444K

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main(void){
    long long num,temp;
    char str[27];
    while(1){
        cin>>num>>str;
        if(num==0&&strcmp(str,"END")==0) break;
        int len,i,j,l,m,n;
        char next;
        len=strlen(str);
        for(i=1;i<len;i++){
            next=str[i];
            for(j=i-1;j>=0&&next>str[j];j--){
                str[j+1]=str[j];
            }
            str[j+1]=next;
        }
        int judge=0;
        for(i=0;i<len;i++){
            for(j=0;j<len;j++){
                if(j==i) continue;
                for(l=0;l<len;l++){
                    if(l==i||l==j) continue;
                    temp=str[i]-'A'+pow(str[j]-'A'+1.0,3.0)+pow(str[l]-'A'+1.0,5.0);
                    if(temp<num) continue;
                    for(m=0;m<len;m++){
                        if(m==i||m==j||m==j) continue;
                        temp=str[i]-'A'+1-pow(str[m]-'A'+1.0,2.0)+pow(str[j]-'A'+1.0,3.0)+pow(str[l]-'A'+1.0,5.0);
                        if(temp<num) continue;
                        for(n=0;n<len;n++){
                            if(n==i||n==j||n==l||n==m) continue;
                            temp=str[i]-'A'+1-pow(str[m]-'A'+1.0,2.0)+pow(str[j]-'A'+1.0,3.0)-pow(str[n]-'A'+1.0,4.0)+pow(str[l]-'A'+1.0,5.0);
                            //cout<<temp<<endl;
                            if(temp==num){
                                cout<<str[i]<<str[m]<<str[j]<<str[n]<<str[l]<<endl;
                                judge=1;
                                break;
                            }
                        }
                        if(judge==1) break;
                    }
                    if(judge==1) break;
                }
                if(judge==1) break;
            }
            if(judge==1) break;
        }
        if(judge==0) cout<<"no solution"<<endl;
    }
    return 0;
}    
        
