/*ZJU 1932 Calories from Fat
2003.12.15 By adai
00:00.02 436K*/

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    char input[5][20];
    char temp[20];
    double c[5]={9,4,4,4,7};
    double fat(0),total(0);
    long rate;
    int i,j,sign(0);
    while(cin>>temp){
        if(strcmp(temp,"-")==0){
            if(sign==0) break;
            else{
                sign=0;
                rate=fat/total*1000;
                if(rate%10<=4) rate/=10;
                else rate=(rate+10)/10;
                cout<<rate<<"%"<<endl;
                fat=total=0;
                continue;
            }
        }
        else{
            sign=1;
            strcpy(input[0],temp);
            for(i=1;i<5;i++){
                cin>>input[i];
            }
            double cal(0),per(100);
            for(i=0;i<5;i++){
                long len=strlen(input[i]);
                long num(0);
                    for(j=0;j<len-1;j++){
                        num=num*10+input[i][j]-'0';
                    }
                if(input[i][len-1]=='g') cal+=num*c[i];
                else if(input[i][len-1]=='C') cal+=num;
                else per-=num;
            }
            total+=cal/(per/100);
            long len=strlen(input[0]);
            long num(0);
            for(j=0;j<len-1;j++){
                num=num*10+input[0][j]-'0';
            }
            if(input[0][len-1]=='g') fat+=num*9;
            else if(input[0][len-1]=='C') fat+=num;
            else fat+=cal/(per/100)*num/100;
        }
    }
    return 0;
}
        
            
