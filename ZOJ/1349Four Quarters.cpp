/*ZJU 1349 Four Quarters
2003.09.29 BY adai
00:00.00 380K*/

#include <stdio.h>

int main(void){
    int i,t,m,n,temp;
    double a[61],b[61];
    double  tempa[61],tempb[61];
    int p[6]={-3,-1,0,1,2,3};
    double q[6]={0.0625,0.125,0.375,0.25,0.125,0.0625};
    double c,tempc,awin,bwin,tie;
    for(i=1;i<=60;i++) a[i]=b[i]=0;
    b[3]=0.0625;
    b[1]=0.125;
    c=0.375;
    a[1]=0.25;
    a[2]=0.125;
    a[3]=0.0625;
    printf("Round   A wins    B wins    Tie\n");
    awin=bwin=tie=0;
    for(i=1;i<=60;i++){
        awin+=a[i];
        bwin+=b[i];
    }
    tie=c;
    awin*=100;
    bwin*=100;
    tie*=100;
    printf("    1   43.7500%%  18.7500%%  37.5000%%\n");
    for(i=1;i<=60;i++){
        tempa[i]=a[i];
        a[i]=0;
        tempb[i]=b[i];
        b[i]=0;
    }
    tempc=c;
    c=0;
    for(t=2;t<=20;t++){
        for(n=0;n<6;n++){
            for(m=1;m<=60;m++){
                if(tempa[m]==0) continue;
                temp=p[n]+m;
                /*if(temp>60||temp<-60) continue;*/
                if(temp>0) a[temp]+=tempa[m]*q[n];
                else if(temp<0){
                    temp*=-1;
                    b[temp]+=tempa[m]*q[n];
                }
                else c+=tempa[m]*q[n];
            }
            for(m=1;m<=60;m++){
                if(tempb[m]==0) continue;
                temp=p[n]-m;
                /*if(temp>60||temp<-60) continue;*/
                if(temp>0) a[temp]+=tempb[m]*q[n];
                else if(temp<0){
                    temp*=-1;
                    b[temp]+=tempb[m]*q[n];
                }
                else c+=tempb[m]*q[n];
            }
        }
        c+=tempc*q[2];
        b[3]+=tempc*q[0];
        b[1]+=tempc*q[1];
        a[1]+=tempc*q[3];
        a[2]+=tempc*q[4];
        a[3]+=tempc*q[5];
        awin=bwin=tie=0;
        for(i=1;i<=60;i++){
            awin+=a[i];
            bwin+=b[i];
        }
        tie=c;
        awin*=100;
        bwin*=100;
        tie*=100;
        printf("%5d   %7.4f%%  %7.4f%%  %7.4f%%\n",t,awin,bwin,tie);
        for(i=1;i<=60;i++){
            tempa[i]=a[i];
            a[i]=0;
            tempb[i]=b[i];
            b[i]=0;
        }
        tempc=c;
        c=0;
    }
    scanf("%d",&n);
    return 0;
}
        
            
            
                
        
    
    
