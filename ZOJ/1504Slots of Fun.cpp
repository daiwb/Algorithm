/*
ZJU 1504 Slots of Fun
00:00.00 484K
2004.07.08 by adai
*/

#include <iostream>
#include <cmath>
using namespace std;
 
class cycle{
public:
        double x;
        double y;
}ball[26][100];
 
int main(){
        char input[100];
        int num[26];            //number of letter(i+'a') appearing in the input
        int no;                 //number of letter to be output
        int n;
        int i,j,k;
        double eps=1e-10;
        while(cin>>n&&n!=0){
                cin>>input;
                for(i=0;i<26;i++)
                        num[i]=0;
                for(i=1;i<=n;i++){
                        for(j=1;j<=i;j++){
                                char c=input[(i*i-i)/2+j-1];
                                k=c-'a';
                                ball[k][num[k]].x=(n-i)/2.0+(j-1)*1;
                                ball[k][num[k]].y=(n-i)*sqrt(3.0)/2;
                                num[k]++;
                        }
                }
                no=0;
                int t1,t2,t3;
                double l1,l2,l3;
                int sign;
                for(i=0;i<26;i++){
                        if(num[i]<3) continue;
                        sign=0;
                        for(t1=0;t1<=num[i]-3;t1++){
                                for(t2=t1+1;t2<=num[i]-2;t2++){
                                        for(t3=t2+1;t3<=num[i]-1;t3++){
                                                l1=sqrt(pow(ball[i][t1].x-ball[i][t2].x,2)+pow(ball[i][t1].y-ball[i][t2].y,2));
                                                l2=sqrt(pow(ball[i][t1].x-ball[i][t3].x,2)+pow(ball[i][t1].y-ball[i][t3].y,2));
                                                l3=sqrt(pow(ball[i][t2].x-ball[i][t3].x,2)+pow(ball[i][t2].y-ball[i][t3].y,2));
                                                if(l1-l2<eps&&l1-l2>-eps&&l2-l3<eps&&l2-l3>-eps){
                                                        cout<<char(i+'a');
                                                        sign=1;
                                                        no++;
                                                        break;
                                                }
                                        }
                                        if(sign==1) break;
                                }
                                if(sign==1) break;
                        }
                        if(no==3) break;
                }
                if(no==0) cout<<"LOOOOOOOOSER!"<<endl;
                else cout<<endl;
        }
        return 0;
}
