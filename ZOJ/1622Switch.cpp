//2003.07.27 by adai

#include <iostream>

using namespace std;

int main(void){
    int n,i,num1,num2,temp,min;
    while(cin>>n){
        int* num=new int[n];
        for(i=0;i<n;i++) cin>>num[i];
        num1=num2=0;
        temp=num[0];
        for(i=1;i<n;i++){
            if(num[i]==temp) num1++;
            temp=(temp+1)%2;
        }
        temp=(num[0]+1)%2;
        num2++;
        for(i=1;i<n;i++){
            if(num[i]==temp) num2++;
            temp=(temp+1)%2;
        }
        min=num1<num2?num1:num2;
        cout<<min<<endl;
        delete []num;
    }
    return 0;
}
        
        
        
