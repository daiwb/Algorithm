/*ZJU 1755 Clay Bully
2003.11.27 By adai
00:00.00 400K*/

#include <cstdio>

using namespace std;

class student{
public:
    int x,y,z;
    int v;
    char name[9];
};

int main(void){
    int n,i;
    while(scanf("%d",&n)&&n!=-1){
        student* stu=new student[n];
        for(i=0;i<n;i++){
            scanf("%d %d %d %s",&stu[i].x,&stu[i].y,&stu[i].z,&stu[i].name);
            stu[i].v=stu[i].x*stu[i].y*stu[i].z;
        }
        int max,min,maxi,mini;
        maxi=mini=0;
        max=stu[maxi].v;
        min=stu[mini].v;
        for(i=1;i<n;i++){
            if(stu[i].v>max){
                max=stu[i].v;
                maxi=i;
            }
            else if(stu[i].v<min){
                min=stu[i].v;
                mini=i;
            }
        }
        printf("%s took clay from %s.\n",stu[maxi].name,stu[mini].name);
        delete []stu;
    }
    return 0;
}
    
