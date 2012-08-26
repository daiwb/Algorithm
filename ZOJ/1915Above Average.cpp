/*ZJU 1915 Above Average
2003.12.02 By adai
00:00.01 444K*/

#include <cstdio>
#include <iostream>

using namespace std;

int main(void){
    int kase;
    cin>>kase;
    while(kase--){
        int n,i,num(0);
        double sum(0),aver;
        cin>>n;
        double* stu=new double[n];
        for(i=0;i<n;i++){
            cin>>stu[i];
            sum+=stu[i];
        }
        aver=sum/n;
        for(i=0;i<n;i++){
            if(stu[i]>aver) num++;
        }
        printf("%.3f",(double)num*100/n);
        cout<<"%"<<endl;
        delete []stu;
    }
    return 0;
}
        
    
