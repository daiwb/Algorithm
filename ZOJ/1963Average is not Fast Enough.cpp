/*ZJU 1963 Average is not Fast Enough!
2003.12.12 By adai
00:00.01 436K*/

#include <iostream>

using namespace std;

int main(void){
    long n,num,i,speed,minute,second;
    double d,time;
    char input[8];
    cin>>n>>d;
    while(cin>>num){
        long sign=1;
        time=0;
        for(i=0;i<n;i++){
            cin>>input;
            if(input[0]=='-'){
                sign=0;
                continue;
            }
            time+=(input[0]-'0')*3600;
            time+=((input[2]-'0')*10+input[3]-'0')*60;
            time+=(input[5]-'0')*10+input[6]-'0';
        }
        speed=time*10/d;
        if(speed%10<=4) speed/=10;
        else speed=(speed+10)/10;
        if(num<=9) cout<<"  ";
        else if(num<=99) cout<<" ";
        cout<<num<<": ";
        if(sign==0){
            cout<<"-"<<endl;
            continue;
        }
        minute=speed/60;
        second=speed-minute*60;
        cout<<minute<<":";
        if(second<=9) cout<<"0";
        cout<<second<<" min/km"<<endl;
    }
    return 0;
}
        
