//ZJU 1178 Booklet Printing
//2003.08.17 BY ADAI

#include <iostream>

using namespace std;

class booklet{
public:
    int page[4];
    booklet(){
        for(int i=0;i<4;i++) page[i]=0;
    }
    ~booklet(){}
};

int main(void){
    int num,n,i,j;
    while(cin>>num&&num!=0){
        if(num%4==0) n=num/4;
        else n=num/4+1;
        booklet* a=new booklet[n];
        j=1;
        for(i=0;i<n;i++){
            if(j==num+1) break;
            a[i].page[1]=j++;
            if(j==num+1) break;
            a[i].page[2]=j++;
        }
        for(i=n-1;i>=0;i--){
            if(j==num+1) break;
            a[i].page[3]=j++;
            if(j==num+1) break;
            a[i].page[0]=j++;
        }
        cout<<"Printing order for "<<num<<" pages:"<<endl;
        for(i=0;i<n;i++){
            if(!(a[i].page[0]==0&&a[i].page[1]==0)){
                cout<<"Sheet "<<i+1<<", front: ";
                if(a[i].page[0]==0) cout<<"Blank";
                else cout<<a[i].page[0];
                cout<<", ";
                if(a[i].page[1]==0) cout<<"Blank";
                else cout<<a[i].page[1];
                cout<<endl;
            }
            if(!(a[i].page[2]==0&&a[i].page[3]==0)){
                cout<<"Sheet "<<i+1<<", back : ";
                if(a[i].page[2]==0) cout<<"Blank";
                else cout<<a[i].page[2];
                cout<<", ";
                if(a[i].page[3]==0) cout<<"Blank";
                else cout<<a[i].page[3];
                cout<<endl;
            }
        }
        delete []a;
    }
    return 0;
}
            
            
        
        
