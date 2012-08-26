/*ZJU 1752 Rectangular Rectitude
2003.11.30 By adai
00:02.65 540K*/

#include <cstdio>

using namespace std;

int main(void){
    int n,color,c,i,j,t,x1,y1,x2,y2,xl,yl,xr,yr,num,kase(1);
    while(scanf("%d %d",&n,&color)){
        if(n==0) break;
        int mat[200][200]={0};
        for(t=0;t<n;t++){
            scanf("%d %d %d %d %d",&c,&x1,&y1,&x2,&y2);
            xl=x1<x2?x1:x2;
            xr=x1+x2-xl;
            yl=y1<y2?y1:y2;
            yr=y1+y2-yl;
            xl+=100;
            xr+=100;
            yl+=100;
            yr+=100;
            for(i=xl;i<xr;i++){
                for(j=yl;j<yr;j++){
                    mat[i][j]=c;
                }
            }
        }
        num=0;
        for(i=0;i<200;i++){
            for(j=0;j<200;j++){
                if(mat[i][j]==color) num++;
            }
        }
        printf("The area of color %d in dataset %d is: %d\n",color,kase++,num);
    }
    return 0;
}
    
            
        
