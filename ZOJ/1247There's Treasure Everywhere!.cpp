/*ZJU 1247 There's Treasure Everywhere!
2003.07.29 by adai*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(void){
    int t=1,len,i;
    int b[4];
    double x,y,dis;
    char a[205];
    while(1){
        scanf("%s",&a);
        if(strcmp(a,"END")==0) break;
        x=y=0;
        b[0]=b[1]=b[2]=b[3]=0;
        for(i=0;a[i]!='\0';i++){
            if(a[i]=='.') break;
            if(a[i]==',') continue;
            len=0;
            while(a[i]>='0'&&a[i]<='9'){
                len=len*10+a[i]-'0';
                i++;
            }
            if(a[i]=='E') b[0]+=len;
            else if(a[i]=='W') b[0]-=len;
            else if(a[i]=='N'){
                if(a[i+1]=='E'){
                    b[2]+=len;
                    i++;
                }
                else if(a[i+1]=='W'){
                    b[3]+=len;
                    i++;
                }
                else b[1]+=len;
            }
            else if(a[i]=='S'){
                if(a[i+1]=='E'){
                    b[3]-=len;
                    i++;
                }
                else if(a[i+1]=='W'){
                    b[2]-=len;
                    i++;
                }
                else b[1]-=len;
            }
        }
        x+=b[0];
        y+=b[1];
        x+=(b[2]-b[3])/2.0*sqrt(2.0);
        y+=(b[2]+b[3])/2.0*sqrt(2.0);
        dis=sqrt(pow(x,2)+pow(y,2));
        if(abs(x)<0.0005) x=0;
        if(abs(y)<0.0005) y=0;
        printf("Map #%d\n",t++);
        printf("The treasure is located at (%.3f,%.3f).\n",x,y);
        printf("The distance to the treasure is %.3f.\n\n",dis);
    }
    return 0;
}

                
                             
