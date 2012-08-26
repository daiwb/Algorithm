/*ZJU 1796 Euchre Results
2003.11.30 By adai
00:00.00 376K*/

#include <cstdio>

using namespace std;

int main(void){
    int win[4],lost[4];
    int i;
    while(scanf("%d %d %d %d %d %d",&win[0],&lost[0],&win[1],&lost[1],&win[2],&lost[2])){
        if(win[0]==0&&lost[0]==0){
            break;
        }
        win[3]=0;
        for(i=0;i<3;i++){
            win[3]+=lost[i]-win[i];
        }
        win[3]=(win[3]+win[0]+lost[0])/2;
        lost[3]=win[0]+lost[0]-win[3];
        printf("Anna's won-loss record is %d-%d.\n",win[3],lost[3]);
    }
    return 0;
}
