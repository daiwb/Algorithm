#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int n,i,j,num,max,temp,judge,t,s;
    while(cin>>n&&n!=0){
        if(n==4){
            int* a=new int[16];
            char ch[5];
            num=max=0;
            for(i=0;i<4;i++){
                cin>>ch;
                for(j=0;j<4;j++){
                    if(ch[j]=='.') a[4*i+j]=0;
                    else{
                        a[4*i+j]=2;
                        num++;
                    }
                }
            }
            num=16-num;
            if(num==0){
                cout<<"0"<<endl;
                continue;
            }
            num=(int)pow(2.0,num);
            for(s=1;s<num;s++){
                judge=0;
                for(j=15;j>=0;j--){
                    if(a[j]==2) continue;
                    else if(a[j]==1) a[j]=0;
                    else{
                        a[j]=1;
                        break;
                    }
                }
                for(i=0;i<4;i++){
                    temp=0;
                    for(j=0;j<4;j++){
                        temp=temp*10+a[4*i+j];
                    }
                    if(temp==2211||temp==2112||temp==1122||
                    temp==2110||temp==2101||temp==2011||temp==2111||
                    temp==1102||temp==1012||temp==112||temp==1112||
                    temp==211||temp==1211||temp==1120||temp==1121||
                    temp==1100||temp==1010||temp==1001||temp==110||
                    temp==101||temp==11||temp==1110||temp==1101||
                    temp==1011||temp==111||temp==1111){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                for(i=0;i<4;i++){
                    temp=0;
                    for(j=0;j<4;j++){
                        temp=temp*10+a[4*j+i];
                    }
                    if(temp==2211||temp==2112||temp==1122||
                    temp==2110||temp==2101||temp==2011||temp==2111||
                    temp==1102||temp==1012||temp==112||temp==1112||
                    temp==211||temp==1211||temp==1120||temp==1121||
                    temp==1100||temp==1010||temp==1001||temp==110||
                    temp==101||temp==11||temp==1110||temp==1101||
                    temp==1011||temp==111||temp==1111){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                t=0;
                for(i=0;i<16;i++){
                    if(a[i]==1) t++;
                }
                if(t>max) max=t;
            }
            delete []a;
            cout<<max<<endl;
        }
        else if(n==3){
            int* a=new int[9];
            char ch[4];
            num=max=0;
            for(i=0;i<3;i++){
                cin>>ch;
                for(j=0;j<3;j++){
                    if(ch[j]=='.') a[3*i+j]=0;
                    else{
                        a[3*i+j]=2;
                        num++;
                    }
                }
            }
            num=9-num;
            if(num==0){
                cout<<"0"<<endl;
                continue;
            }
            num=(int)pow(2.0,num);
            for(s=1;s<num;s++){
                judge=0;
                for(j=8;j>=0;j--){
                    if(a[j]==2) continue;
                    else if(a[j]==1) a[j]=0;
                    else{
                        a[j]=1;
                        break;
                    }
                }
                for(i=0;i<3;i++){
                    temp=0;
                    for(j=0;j<3;j++){
                        temp=temp*10+a[3*i+j];
                    }
                    if(temp==211||temp==112||temp==110||
                    temp==101||temp==11||temp==111){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                for(i=0;i<3;i++){
                    temp=0;
                    for(j=0;j<3;j++){
                        temp=temp*10+a[3*j+i];
                    }
                    if(temp==211||temp==112||temp==110||
                    temp==101||temp==11||temp==111){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                t=0;
                for(i=0;i<9;i++){
                    if(a[i]==1) t++;
                }
                if(t>max) max=t;
            }
            delete []a;
            cout<<max<<endl;
        }
        else if(n==2){
            int* a=new int[4];
            char ch[3];
            num=max=0;
            for(i=0;i<2;i++){
                cin>>ch;
                for(j=0;j<2;j++){
                    if(ch[j]=='.') a[2*i+j]=0;
                    else{
                        a[2*i+j]=2;
                        num++;
                    }
                }
            }
            num=4-num;
            if(num==0){
                cout<<"0"<<endl;
                continue;
            }
            num=(int)pow(2.0,num);
            for(s=1;s<num;s++){
                judge=0;
                for(j=3;j>=0;j--){
                    if(a[j]==2) continue;
                    else if(a[j]==1) a[j]=0;
                    else{
                        a[j]=1;
                        break;
                    }
                }
                for(i=0;i<2;i++){
                    temp=0;
                    for(j=0;j<2;j++){
                        temp=temp*10+a[2*i+j];
                    }
                    if(temp==11){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                for(i=0;i<2;i++){
                    temp=0;
                    for(j=0;j<2;j++){
                        temp=temp*10+a[2*j+i];
                    }
                    if(temp==11){
                        judge=1;
                        break;
                    }
                }
                if(judge==1) continue;
                t=0;
                for(i=0;i<4;i++){
                    if(a[i]==1) t++;
                }
                if(t>max) max=t;
            }
            delete []a;
            cout<<max<<endl;
        }
        else{
            char ch;
            cin>>ch;
            if(ch=='.') cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    return 0;
}
               
                
            
            
            
