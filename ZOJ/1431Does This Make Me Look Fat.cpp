/*ZJU 1431 Does This Make Me Look Fat?
2003.10.04 BY adai
00:00.00 436K*/

#include <iostream>
#include <cstring>

using namespace std;

class dieter{
public:
    char name[21];
    int day;
    int weight; //starting weight
    int wei;    //weight now
}people[10];

void insertion_sort(dieter people[10],int num){
    int i,j;
    dieter next;
    for(i=1;i<num;i++){
        next=people[i];
        for(j=i-1;j>=0&&next.wei>people[j].wei;j--)
            people[j+1]=people[j];
        people[j+1]=next;
    }
}

int main(void){
    char temp[21];
    int num,i,kase(0);
    while(cin>>temp){
        if(kase++) cout<<endl;
        num=0;
        while(1){
            cin>>temp;
            if(strcmp(temp,"END")==0){
                insertion_sort(people,num);
                for(i=0;i<num;i++) cout<<people[i].name<<endl;
                break;
            }
            else{
                strcpy(people[num].name,temp);
                cin>>people[num].day>>people[num].weight;
                people[num].wei=people[num].weight-people[num].day;
                if(people[num].wei<1) people[num].wei=1;
                num++;
            }
        }
    }
    return 0;
}
