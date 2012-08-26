//ZJU 1184 Counterfeit Dollar
//2003.09.14 BY adai

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    long kase,len;
    cin>>kase;
    while(kase--){
        int coin[12]={0};//coin[i]为0表示不能判断，为1表示为真，为2表示可能超重，为3表示可能偏轻 
        char left[3][7],right[3][7],res[3][5];
        int i,j;
        int temp[12];
        for(i=0;i<3;i++){
            for(j=0;j<12;j++) temp[j]=0;
            cin>>left[i]>>right[i]>>res[i];
            len=strlen(left[i]);
            if(res[i][0]=='e'){
                for(j=0;j<len;j++) coin[left[i][j]-'A']=coin[right[i][j]-'A']=1;
            }
            else if(res[i][0]=='u'){
                for(j=0;j<len;j++){
                    if(coin[left[i][j]-'A']!=1){
                        coin[left[i][j]-'A']=2;
                        temp[left[i][j]-'A']=1;
                    }
                    if(coin[right[i][j]-'A']!=1){
                        coin[right[i][j]-'A']=3;
                        temp[right[i][j]-'A']=1;
                    }
                }
                for(j=0;j<12;j++){
                    if(temp[j]==0) coin[j]=1;
                }
            }
            else if(res[i][0]=='d'){
                for(j=0;j<len;j++){
                    if(coin[left[i][j]-'A']!=1){
                        coin[left[i][j]-'A']=3;
                        temp[left[i][j]-'A']=1;
                    }
                    if(coin[right[i][j]-'A']!=1){
                        coin[right[i][j]-'A']=2;
                        temp[right[i][j]-'A']=1;
                    }
                }
                for(j=0;j<12;j++){
                    if(temp[j]==0) coin[j]=1;
                }
            }
        }
        int judge,m,n;
        for(i=0;i<12;i++){
            if(coin[i]==1) continue;
            judge=1;
            if(coin[i]==0){
                for(m=0;m<3;m++){
                    len=strlen(left[m]);
                    for(n=0;n<len;n++){
                        if(left[m][n]-'A'==i){
                            if(res[m][0]!='u') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                    for(n=0;n<len;n++){
                        if(right[m][n]-'A'==i){
                            if(res[m][0]!='d') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                }
                if(judge==1){
                    cout<<char(i+'A')<<" is the counterfeit coin and it is heavy."<<endl;
                    break;
                }
                judge=1;
                for(m=0;m<3;m++){
                    len=strlen(left[m]);
                    for(n=0;n<len;n++){
                        if(left[m][n]-'A'==i){
                            if(res[m][0]!='d') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                    for(n=0;n<len;n++){
                        if(right[m][n]-'A'==i){
                            if(res[m][0]!='u') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                }
                if(judge==1){
                    cout<<char(i+'A')<<" is the counterfeit coin and it is light."<<endl;
                    break;
                }
            }
            else if(coin[i]==2){
                for(m=0;m<3;m++){
                    len=strlen(left[m]);
                    for(n=0;n<len;n++){
                        if(left[m][n]-'A'==i){
                            if(res[m][0]!='u') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                    for(n=0;n<len;n++){
                        if(right[m][n]-'A'==i){
                            if(res[m][0]!='d') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                }
                if(judge==1){
                    cout<<char(i+'A')<<" is the counterfeit coin and it is heavy."<<endl;
                    break;
                }
            }
            else{
                for(m=0;m<3;m++){
                    len=strlen(left[m]);
                    for(n=0;n<len;n++){
                        if(left[m][n]-'A'==i){
                            if(res[m][0]!='d') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                    for(n=0;n<len;n++){
                        if(right[m][n]-'A'==i){
                            if(res[m][0]!='u') judge=0;
                            break;
                        }
                    }
                    if(judge==0) break;
                }
                if(judge==1){
                    cout<<char(i+'A')<<" is the counterfeit coin and it is light."<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
                
                    
                
                
                
                
            
                
                    
