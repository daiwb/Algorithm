#include <iostream>
#include <string>

using namespace std;

int main(void){
    int len1,len2,len,t,i,j,num,max,temp;
    char a[300],b[300];
    while(cin>>a&&strcmp(a,"-1")!=0){
        cin>>b;
        len1=strlen(a);
        len2=strlen(b);
        len=len1+len2;
        max=0;
        for(t=1-len1;t<=len2-1;t++){
            num=0;
            if(t<0){
                i=-t;
                j=0;
                while(1){
                    if(a[i++]==b[j++]) num++;
                    if(a[i]=='\0'||b[j]=='\0') break;
                }
                if(num>max) max=num;
            }
            else{
                i=0;
                j=t;
                while(1){
                    if(a[i++]==b[j++]) num++;
                    if(a[i]=='\0'||b[j]=='\0') break;
                }
                if(num>max) max=num;
            }
        }
        max*=2;
        if(max==0){
            cout<<"appx("<<a<<","<<b<<") = 0"<<endl;
        }
        else if(max==len){
            cout<<"appx("<<a<<","<<b<<") = 1"<<endl;
        }
        else{
            temp=max<len?max:len;
            for(t=2;t<=temp;t++){
                while(max%t==0&&len%t==0){
                    max/=t;
                    len/=t;
                }
            }
            cout<<"appx("<<a<<","<<b<<") = "<<max<<"/"<<len<<endl;
        }
    }
    return 0;
}
            
            
                    
            
