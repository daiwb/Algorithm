/*ZJU Average Speed
2003.12.02 By adai
00:00.00 380K*/

#include <iostream>
#include <cstdio>
#include <cstring>

int main(void){
    char input[20];
    double dis(0),speed(0),time[2]={0};
    while(gets(input)){
        int i,len=strlen(input);
        if(len==8){
            time[1]=0;
            time[1]=((input[0]-'0')*10+input[1]-'0')*3600;
            time[1]+=((input[3]-'0')*10+input[4]-'0')*60;
            time[1]+=(input[6]-'0')*10+input[7]-'0';
            dis+=(time[1]-time[0])*speed/3600;
            time[0]=time[1];
            printf("%s %.2f km\n",input,dis);
        }
        else{
            time[1]=0;
            time[1]=((input[0]-'0')*10+input[1]-'0')*3600;
            time[1]+=((input[3]-'0')*10+input[4]-'0')*60;
            time[1]+=(input[6]-'0')*10+input[7]-'0';
            dis+=(time[1]-time[0])*speed/3600;
            time[0]=time[1];
            speed=0;
            for(i=9;i<len;i++){
                speed=speed*10+input[i]-'0';
            }
        }
    }
    return 0;
}
            
        
        
