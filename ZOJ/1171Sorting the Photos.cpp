//ZJU 1171 Sorting the Photos
//2003.08.17 BY ADAI

#include <iostream>
#include <cstring>

using namespace std;

int main(void){
    int t,kase,i;
    scanf("%d", &kase);
    //cin>>kase;
    for(t=0;t<kase;t++){
        if(t) printf("\n");
        //if(t) cout<<endl;
        int num,no(0),n(0);
        char temp[20];
        char c;
        c='T';
        scanf("%d", &num);
        //cin>>num;
        while(1){
            scanf("%s", temp);
            //cin>>temp;
            for(i=0;temp[i]!='\0';i++){
                if(temp[i]!=c){
                    no++;
                    c=temp[i];
                }
            }
            n+=strlen(temp);
            if(n==num) break;
        }
        no--;
        printf("%d\n", no);
        //cout<<no<<endl;
    }
    return 0;
}
            
