/*ZJU 1656 To Win the Honor
2003.10.27 BY adai
00:00.00 440K*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

double pi=acos(0.0+-1);

class player{
public:
    char name[50];
    int sp;             //stand for shoot-power
    double sa;          //stand for shoot-accuracy
    double pr;          //stand for probabilitie
}pla[11];

int main(void){
    int kase=1,i,j,t;
    double sla,r,time,angle,temp;
    char input[50];
    while(cin>>input){
        if(strcmp(input,"END")==0) break;
        strcpy(pla[0].name,input);
        cin>>pla[0].sp>>pla[0].sa;
        for(i=1;i<11;i++){
            cin>>pla[i].name>>pla[i].sp>>pla[i].sa;
        }
        for(t=0;t<11;t++){
            pla[t].sa=0.05*pla[t].sa;
            time=sqrt(121/(pow(0.0+pla[t].sp,2)-25));
            r=time*5;
            if(r<=2.5){
                sla=pi*pow(0.0+r,2)/2;
            }
            else if(r<=3.75){
                temp=sqrt(pow(0.0+r,2)-6.25)*2;
                angle=acos(0.0+2.5/r)*2;
                sla=pi*pow(0.0+r,2)/2-(angle*pow(0.0+r,2)/2-temp*2.5/2);
            }
            else if(r<=sqrt(20.3125)){
                temp=sqrt(pow(0.0+r,2)-6.25)*2;
                angle=acos(0.0+2.5/r)*2;
                sla=pi*pow(0.0+r,2)/2-(angle*pow(0.0+r,2)/2-temp*2.5/2);
                temp=sqrt(pow(0.0+r,2)-14.0625);
                angle=acos(0.0+3.75/r);
                sla-=(angle*pow(0.0+r,2)/2-temp*3.75/2)*2;
            }
            else{
                sla=18.75;
            }
            pla[t].pr=(18.75-sla)/18.75;
            pla[t].pr*=pla[t].sa;
        }
        player next;
        for(i=1;i<11;i++){
            next=pla[i];
            for(j=i-1;j>=0&&strcmp(next.name,pla[j].name)<0;j--){
                pla[j+1]=pla[j];
            }
            pla[j+1]=next;
        }
        for(i=1;i<11;i++){
            next=pla[i];
            for(j=i-1;j>=0&&next.pr>pla[j].pr;j--){
                pla[j+1]=pla[j];
            }
            pla[j+1]=next;
        }
        cout<<"Case "<<kase++<<":"<<endl;
        for(i=0;i<5;i++){
            printf("%s %.2f",pla[i].name,100*pla[i].pr);
            cout<<"%"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
            
                
                
                
                
                
                
