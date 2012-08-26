//ZJU 1098 Simple Computers

#include <iostream>

using namespace std;
 
struct{
    int cmd,num;
}mem[32]; 

int convert(char *s,int sta,int end) 
{ 
    int i,num=0; 
    for(i=sta;i<=end;i++) 
    num=num*2+s[i]-'0'; 
    return num; 
} 

void divide(char *s,int num) 
{ 
    int i; 
    for(i=0;i<=7;i++) s[i]='0'; 
    s[i]=0; 
    i=7; 
    while(num){
        s[i--]=num%2+'0';
        num/=2;
    } 
} 
void fill(int x,int num) 
{ 
   char str[9]; 
   divide(str,num); 
   mem[x].cmd=convert(str,0,2); 
   mem[x].num=convert(str,3,7); 
} 

int main() 
{ 
    int i; char str[9]; 
    while(cin>>str){ 
        mem[0].cmd = convert(str,0,2); 
        mem[0].num = convert(str,3,7); 
        for(i=1;i<=31;i++) 
        { 
        cin>>str; 
        mem[i].cmd = convert(str,0,2); 
        mem[i].num = convert(str,3,7); 
        }
        int cmd,x,acc,pc,i; 
        char res[9]; 
        acc=pc=0;
        cmd=mem[0].cmd; 
        while(cmd!=7){ 
            x=mem[pc].num; 
            pc++;
            pc%=32; 
            switch(cmd){ 
                case 0: fill(x,acc);break; 
                case 1: acc=mem[x].cmd*32+mem[x].num;break; 
                case 2: if(acc==0) pc=x;break; 
                case 3: break; 
                case 4: acc=(acc+255)%256;break; 
                case 5: acc=(acc+1)%256;break; 
                case 6: pc=x;break; 
            } 
            cmd=mem[pc].cmd; 
        } 
        divide(res,acc); 
        cout<<res<<endl; 
    }
    return 0; 
} 

