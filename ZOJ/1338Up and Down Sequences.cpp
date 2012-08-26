//ZJU 1338 Up and Down Sequences
//2003.09.17 BY adai

#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    long m,n;
    while(cin>>m&&m!=0){
        int numu(0),numd(0),lenu(0),lend(0),len(0);
        int value(1),sign(0);
        while(scanf("%d",&n)!=EOF){
            if(n==0){
                if(sign==1){
                    numu++;
                    lenu+=len;
                }
                else if(sign==-1){
                    numd++;
                    lend+=len;
                }
                break;
            }
            value++;
            if(sign==0){
                len++;
                if(n>m) sign=1;
                else if(n<m) sign=-1;
            }
            else if(sign==1){
                if(n>=m) len++;
                else{
                    sign=-1;
                    numu++;
                    lenu+=len;
                    len=1;
                }
            }
            else{
                if(n<=m) len++;
                else{
                    sign=1;
                    numd++;
                    lend+=len;
                    len=1;
                }
            }
            m=n;
        }
        printf("Nr values = %d:  ",value);
        if(numu==0) printf("0.000000 ");
        else printf("%.6f ",(float)lenu/(float)numu);
        if(numd==0) printf("0.000000\n");
        else printf("%.6f\n",(float)lend/(float)numd);
    }
    return 0;
}
        
                    
            
            
