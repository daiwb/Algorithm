/*ZJU 1159 487-3279
2003.08.29 BY ADAI
quick sort
00:01.93 824K*/

#include <iostream>
#include <cstring>

using namespace std;

long phn[100001];

void quicksort(long phn[],int left,int right){
    long temp,pivot;
    int i,j;
    if(left<right){
        i=left;
        j=right+1;
        pivot=phn[left];
        do{
            do
                i++;
            while(phn[i]<pivot);
            do
                j--;
            while(phn[j]>pivot);
            if(i<j){
                temp=phn[i];
                phn[i]=phn[j];
                phn[j]=temp;
            }
        }while(i<j);
        temp=phn[left];
        phn[left]=phn[j];
        phn[j]=temp;
        quicksort(phn,left,j-1);
        quicksort(phn,j+1,right);
    }
}                      

int main(void){
    long kase,k,i,j;
    cin>>kase;
    for(k=0;k<kase;k++){
        if(k) cout<<endl;
        long n,count;    
        char input[200],temp[8];
        cin>>n;
        for(i=0;i<n;i++){
            cin>>input;
            count=0;
            for(j=0;input[j]!='\0';j++){
                if(input[j]=='-') continue;
                else if(input[j]>='A'&&input[j]<='C') temp[count++]='2';
                else if(input[j]>='D'&&input[j]<='F') temp[count++]='3';
                else if(input[j]>='G'&&input[j]<='I') temp[count++]='4';
                else if(input[j]>='J'&&input[j]<='L') temp[count++]='5';
                else if(input[j]>='M'&&input[j]<='O') temp[count++]='6';
                else if(input[j]>='P'&&input[j]<='S') temp[count++]='7';
                else if(input[j]>='T'&&input[j]<='V') temp[count++]='8';
                else if(input[j]>='W'&&input[j]<='Y') temp[count++]='9';
                else temp[count++]=input[j];
            }
            temp[count]='\0';
            long phnum=0;
            for(j=0;j<7;j++) phnum=phnum*10+temp[j]-'0';
            phn[i]=phnum;
        }
        quicksort(phn,0,n-1);
        long t=1,jud=0;
        for(i=1;i<n;i++){
            if(phn[i]==phn[i-1]){
                jud=1;
                t++;
            }
            else{
                if(t>1){
                    long tempnum=1000000;
                    for(j=0;j<3;j++){
                        cout<<(phn[i-1]/tempnum)%10;
                        tempnum/=10;
                    }
                    cout<<"-";
                    for(;j<7;j++){
                        cout<<(phn[i-1]/tempnum)%10;
                        tempnum/=10;
                    }
                    cout<<" "<<t<<endl;
                }
                t=1;
            }
        }
        if(t>1){
            long tempnum=1000000;
            for(j=0;j<3;j++){
                cout<<(phn[i-1]/tempnum)%10;
                tempnum/=10;
            }
            cout<<"-";
            for(;j<7;j++){
                cout<<(phn[i-1]/tempnum)%10;
                tempnum/=10;
            }
            cout<<" "<<t<<endl;
            jud=1;
        }
        if(jud==0) cout<<"No duplicates."<<endl;
    }
    return 0;
}
        
        
    
    
