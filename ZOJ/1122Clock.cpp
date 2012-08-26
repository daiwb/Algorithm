#include <iostream>

using namespace std;

int main(void){
    int x1,y1,x2,y2,a1,a2,n,i;
    cout<<"Program 3 by team X"<<endl;
    cout<<"Initial time  Final time  Passes"<<endl;
    while(cin>>x1>>y1>>x2>>y2){
        cout<<"       ";
        if(x1>9) cout<<x1;
        else cout<<"0"<<x1;
        cout<<":";
        if(y1>9) cout<<y1;
        else cout<<"0"<<y1;
        cout<<"       ";
        if(x2>9) cout<<x2;
        else cout<<"0"<<x2;
        cout<<":";
        if(y2>9) cout<<y2;
        else cout<<"0"<<y2;
        cout<<"      ";
        n=0;
        if(x1==x2&&y1<y2){
            a1=x1%12;
            a2=x1%12;
            if( 60*a1>11*y1 && 60*a2<11*y2 ) n++;
        }
        else{
            a1=x1%12;
            a2=x2%12;
            if(60*a1>11*y1&&a1!=11) n++;
            i=x1+1;
            while(1){
                if(i>12) i=1;
                if(i==x2) break;
                if(i!=11) n++;
                i++;
            }
            if(60*a2<11*y2) n++;
        }
        if(n>9) cout<<n<<endl;
        else cout<<" "<<n<<endl;
    }
    cout<<"End of program 3 by team X"<<endl;
    return 0;
}
                
            
            
