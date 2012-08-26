//ZJU 1024 Calendar Game
//2003.08.12 BY ADAI

#include <iostream>

using namespace std;

int main(void){
    int i,j,year,month,day,ty,tm,td,ty1,tm1,td1;
    int kase,win;
    int date[102][12][31];
    for(year=0;year<102;year++){
        for(month=0;month<12;month++){
            for(day=0;day<31;day++){
                date[year][month][day]=2;
            }
        }
    }
    for(i=3;i<31;i++) date[101][10][i]=-1;
    for(i=0;i<31;i++) date[101][11][i]=-1;
    for(i=0;i<102;i++){
        date[i][3][30]=date[i][5][30]=date[i][8][30]=date[i][10][30]=-1;
    }
    for(i=0;i<102;i++){
        year=1900+i;
        if(year%400==0||(year%4==0&&year%100!=0)){
            date[i][1][29]=date[i][1][30]=-1;
        }
        else date[i][1][28]=date[i][1][29]=date[i][1][30]=-1;
    }
    date[101][10][2]=1;
    date[101][11][30]=0;
    for(year=101;year>=0;year--){
        for(month=11;month>=0;month--){
            for(day=30;day>=0;day--){
                if(date[year][month][day]==-1) continue;
                if(date[year][month][day]==1) continue;
                if(date[year][month][day]==0) continue;
                ty=year;
                tm=month;
                td=day;
                td++;
                if(td>30){
                    td=0;
                    tm++;
                }
                if(tm>11){
                    tm=0;
                    ty++;
                }
                while(date[ty][tm][td]==-1){
                    td++;
                    if(td>30){
                        td=0;
                        tm++;
                    }
                    if(tm>11){
                        tm=0;
                        ty++;
                    }
                }
                win=1;
                ty1=ty;
                tm1=tm;
                td1=td;
                td1++;
                if(td1>30){
                    td1=0;
                    tm1++;
                }
                if(tm1>11){
                    tm1=0;
                    ty1++;
                }
                while(date[ty1][tm1][td1]==-1){
                    td1++;
                    if(td1>30){
                        td1=0;
                        tm1++;
                    }
                    if(tm1>11){
                        tm1=0;
                        ty1++;
                    }
                }
                if(date[ty1][tm1][td1]==0) win=0;
                ty1=ty;
                tm1=tm;
                td1=td;
                tm1++;
                if(tm1>11){
                    tm1=0;
                    ty1++;
                }
                if(date[ty1][tm1][td1]==0) win=0;
                if(win==1){
                    date[year][month][day]=1;
                    continue;
                }
                ty=year;
                tm=month;
                td=day;
                tm++;
                if(tm>11){
                    tm=0;
                    ty++;
                }
                if(date[ty][tm][td]==-1){
                    date[year][month][day]=0;
                    continue;
                }
                win=1;
                ty1=ty;
                tm1=tm;
                td1=td;
                td1++;
                if(td1>30){
                    td1=0;
                    tm1++;
                }
                if(tm1>11){
                    tm1=0;
                    ty1++;
                }
                while(date[ty1][tm1][td1]==-1){
                    td1++;
                    if(td1>30){
                        td1=0;
                        tm1++;
                    }
                    if(tm1>11){
                        tm1=0;
                        ty1++;
                    }
                }
                if(date[ty1][tm1][td1]==0) win=0;
                ty1=ty;
                tm1=tm;
                td1=td;
                tm1++;
                if(tm1>11){
                    tm1=0;
                    ty1++;
                }
                if(date[ty1][tm1][td1]==0) win=0;
                if(win==1) date[year][month][day]=1;
                else date[year][month][day]=0;
            }
        }
    }
    cin>>kase;
    while(kase--){
        cin>>year>>month>>day;
        year-=1900;
        month-=1;
        day-=1;
        if(date[year][month][day]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
    
                
                
                
                
