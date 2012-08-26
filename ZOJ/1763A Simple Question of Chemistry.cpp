/*ZJU 1763 A Simple Question of Chemistry
2003.11.21 By adai
00:00.00 380L*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    float t1,t2;
    scanf("%f",&t1);
    while(scanf("%f",&t2)){
        if(t2==999){
            printf("End of Output\n");
            break;
        }
        printf("%.2f\n",t2-t1);
        t1=t2;
    }
    return 0;
}
