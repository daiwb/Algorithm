//ZJU 1179 Finding Rectangles
//2003.08.03 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int n,kase=1,i,t,a1,a2,a3,a4,num,judge;
    while(cin>>n&&n!=0){
        char* ch=new char[n];
        int* x=new int[n];
        int* y=new int[n];
        for(i=0;i<n;i++){
            cin>>ch[i];
            cin>>x[i]>>y[i];
        }
        cout<<"Point set "<<kase++<<":";
        num=judge=0;
        for(a1=0;a1<n;a1++){
            for(a2=0;a2<n;a2++){
                if(y[a2]!=y[a1]||x[a2]<=x[a1]) continue;
                for(a3=0;a3<n;a3++){
                    if(x[a3]!=x[a2]||y[a3]>=y[a2]) continue;
                    for(a4=0;a4<n;a4++){
                        if(y[a4]==y[a3]&&x[a4]==x[a1]){
                            judge=1;
                            num++;
                            if(num==10) num=0;
                            if(num==1) cout<<endl;  
                            cout<<" "<<ch[a1]<<ch[a2]<<ch[a3]<<ch[a4];
                        }
                    }
                }
            }
        }
        if(judge==0) cout<<" No rectangles";
        cout<<endl;
        delete []x;
        delete []y;
        delete []ch;
    }
    return 0;
}
