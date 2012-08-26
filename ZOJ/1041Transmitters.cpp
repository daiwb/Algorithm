//ZJU 1041 Transmitters
//2003.09.13 BY adai

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int i,j;
    double rx,ry,r,tx,ty,temp;
    while(1){
        cin>>rx>>ry>>r;
        if(r<=0) break;
        int num;
        cin>>num;
        int* x=new int[num];
        int* y=new int[num];
        int t=0;
        for(i=0;i<num;i++){
            cin>>x[t]>>y[t];
            if(pow(rx-x[t],2)+pow(ry-y[t],2)<=pow(r,2)) t++;
        }
        int max=0;
        int left,right;
        for(i=0;i<t;i++){
            if(x[i]==rx&&y[i]==ry){
                if(max==0) max=1;
                continue;
            }
            tx=x[i];
            ty=y[i];
            left=right=1;
            j=i;
            while(1){
                j++;
                if(j>=t) j=0;
                if(j==i) break;
                if(x[j]==rx&&y[j]==ry){
                    left++;
                    right++;
                    continue;
                }
                temp=(y[j]-ry)*(tx-rx)-(x[j]-rx)*(ty-ry);
                if(temp>=0) left++;
                if(temp<=0) right++;
            }
            if(left>max) max=left;
            if(right>max) max=right;
        }
        delete []x;
        delete []y;
        cout<<max<<endl;
    }
    return 0;
}
                
            
            
    
