//2003.07.26 by adai

#include <iostream>
#include <string>

using namespace std;

int main(void){
    int code[30]={12,2111,2121,211,1,1121,221,1111,11,1222,212,1211,22,21,222,
        1221,2212,121,111,2,112,1112,122,2112,2122,2211,1122,1212,2221,2222};
    int t,c;
    cin>>t;
    for(c=1;c<=t;c++){
        char a[105];
        cin>>a;
        int i,j,m,n,s,p,lena,temp;
        char ch;
        lena=strlen(a);
        int* b=new int[lena*4];
        int* len=new int[lena];
        m=j=0;
        for(i=0;i<lena;i++){
            if(a[i]>='A'&&a[i]<='Z'){
                temp=code[a[i]-'A'];
                if(temp<10){
                    len[m++]=1;
                    b[j++]=temp;
                }
                else if(temp<100){
                    len[m++]=2;
                    b[j++]=temp/10%10;
                    b[j++]=temp%10;
                }
                else if(temp<1000){
                    len[m++]=3;
                    b[j++]=temp/100%10;
                    b[j++]=temp/10%10;
                    b[j++]=temp%10;
                }
                else{
                    len[m++]=4;
                    b[j++]=temp/1000%10;
                    b[j++]=temp/100%10;
                    b[j++]=temp/10%10;
                    b[j++]=temp%10;
                }
            }
            else if(a[i]=='_'){
                temp=1122;
                len[m++]=4;
                b[j++]=temp/1000%10;
                b[j++]=temp/100%10;
                b[j++]=temp/10%10;
                b[j++]=temp%10;
            }
            else if(a[i]==','){
                temp=1212;
                len[m++]=4;
                b[j++]=temp/1000%10;
                b[j++]=temp/100%10;
                b[j++]=temp/10%10;
                b[j++]=temp%10;
            }
            else if(a[i]=='.'){
                temp=2221;
                len[m++]=4;
                b[j++]=temp/1000%10;
                b[j++]=temp/100%10;
                b[j++]=temp/10%10;
                b[j++]=temp%10;
            }
            else if(a[i]=='?'){
                temp=2222;
                len[m++]=4;
                b[j++]=temp/1000%10;
                b[j++]=temp/100%10;
                b[j++]=temp/10%10;
                b[j++]=temp%10;
            }
        }
        cout<<c<<": ";
        j=0;
        for(m--;m>=0;m--){
            temp=0;
            for(s=0;s<len[m];s++){
                temp=temp*10+b[j+s];
            }
            for(p=0;p<30;p++){
                if(code[p]==temp) break;
            }
            if(p<26){
                ch=p+'A';
                cout<<ch;
            }
            else if(p==26) cout<<"_";
            else if(p==27) cout<<",";
            else if(p==28) cout<<".";
            else cout<<"?";
            j+=len[m];
        }
        cout<<endl;
        delete []b;
        delete []len;
    }         
}
