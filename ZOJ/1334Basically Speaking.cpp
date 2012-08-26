#include <iostream>

using namespace std;

int main(void){
    int mf,mt;
    char input[7],output[7];
    while(cin>>input>>mf>>mt){
        long num=0;
        int i,j,temp;
        for(i=0;input[i]!='\0';i++){
            if(input[i]>='0'&&input[i]<='9') temp=input[i]-'0';
            else if(input[i]>='A'&&input[i]<='F') temp=input[i]-'A'+10;
            num=num*mf+temp;
        }
        i=6;
        while(1){
            if(i<0) break;
            temp=num%mt;
            if(temp>=0&&temp<=9) output[i]=temp+'0';
            else output[i]=temp-10+'A';
            num/=mt;
            if(num==0) break;
            i--;
        }
        if(i<0){
            cout<<"  ERROR"<<endl;
            continue;
        }
        for(j=0;j<i;j++) cout<<" ";
        for(j=i;j<7;j++) cout<<output[j];
        cout<<endl;
    }
    return 0;
}
        
            
            
    
