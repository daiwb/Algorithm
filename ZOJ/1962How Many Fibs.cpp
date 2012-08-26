/*ZJU 1962 How Many Fibs?
2003.12.07 By adai
00:00.01 544K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char fib[1000][105];
    char a[105],b[105];
    int* len=new int[1000];
    int t,i,j,add,temp;
    for(i=0;i<1000;i++){
        for(j=0;j<104;j++) fib[i][j]='0';
        fib[i][104]='\0';
    }
    fib[1][103]='1';
    len[1]=1;
    fib[2][103]='2';
    len[2]=1;
    for(t=3;t<1000;t++){
        add=0;
        for(i=103;i>=104-len[t-2];i--){
            temp=fib[t-1][i]-'0'+fib[t-2][i]-'0'+add;
            if(temp>9){
                fib[t][i]=temp-10+'0';
                add=1;
            }
            else{
                fib[t][i]=temp+'0';
                add=0;
            }
        }
        for(;i>=104-len[t-1];i--){
            temp=fib[t-1][i]-'0'+add;
            if(temp>9){
                fib[t][i]=temp-10+'0';
                add=1;
            }
            else{
                fib[t][i]=temp+'0';
                add=0;
            }
        }
        if(add==1){
            fib[t][i]='1';
            len[t]=len[t-1]+1;
        }
        else len[t]=len[t-1];
    }
    //for(t=480;t<490;t++) cout<<fib[t]<<endl<<endl;
    char ta[105],tb[105];
    while(cin>>ta>>tb){
        if(strcmp(ta,"0")==0&&strcmp(tb,"0")==0) break;
        int lena,lenb;
        lena=strlen(ta);
        lenb=strlen(tb);
        for(i=lena-1;i>=0;i--){
            a[104-lena+i]=ta[i];
        }
        for(i=0;i<104-lena;i++) a[i]='0';
        a[104]='\0';
        for(i=lenb-1;i>=0;i--){
            b[104-lenb+i]=tb[i];
        }
        for(i=0;i<104-lenb;i++) b[i]='0';
        b[104]='\0';
        for(i=1;i<490;i++){
            if(strcmp(fib[i],a)>=0) break;
        }
        for(j=i;j<490;j++){
            if(strcmp(fib[j],b)>0) break;
        }
        cout<<j-i<<endl;
    }
    delete []len;
    return 0;
}
        
        
