//ZJU 1636 Evaluate Matrix Sum
//2003.09.06 BY adai

#include <iostream.h>
#include <stdio.h>

int main(void){
    int t,kase;
    scanf("%d",&t);
    for(kase=1;kase<=t;kase++){
        int row,col,i,j,num;
        unsigned long sum[505][505]={0};
        scanf("%d %d",&row,&col);
        long temp[505]={0};
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){ 
                scanf("%d",&num);
                temp[j]+=num*num;
                sum[i][j]=sum[i][j-1]+temp[j];
            }
        }
        //for(i=1;i<=row;i++){
        //   for(j=1;j<=col;j++) cout<<sum[i][j]<<" ";
        //    cout<<endl;
        //}
        printf("Case %d:\n",kase);
        long no;
        scanf("%d",&no);
        int r1,c1,r2,c2;
        while(no--){
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            printf("%d\n",sum[r2][c2]-sum[r2][c1-1]-sum[r1-1][c2]+sum[r1-1][c1-1]);
        }
    }
    return 0;
}
            
        
        
