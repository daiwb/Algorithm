//ZJU 1453 Surround the Trees
//2003.09.19 BY adai
//Graham Scan 

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

class point{
public:
    double x,y;
    point(){}
    ~point(){}
};

int main(void){
    long n,i,j;
    while(cin>>n&&n!=0){
        double len;
        point* tree=new point[n];
        for(i=0;i<n;i++) cin>>tree[i].x>>tree[i].y;
        if(n==1){
            cout<<"0.00"<<endl;
            delete []tree;
            continue;
        }
        if(n==2){
            len=2*sqrt(pow(tree[0].x-tree[1].x,2)+pow(tree[0].y-tree[1].y,2));
            printf("%.2f\n",len);
            delete []tree;
            continue;
        }
        long tempnum;//找出起始点
        point temp;
        temp=tree[0];
        tempnum=0;
        for(i=1;i<n;i++){
            if((tree[i].y)<(temp.y)){
                temp=tree[i];
                tempnum=i;
                
            }
            else if(((tree[i].y)==(temp.y))&&((tree[i].x)<(temp.x))){
                temp=tree[i];
                tempnum=i;
                
            }
        }
        temp=tree[0];
        tree[0]=tree[tempnum];
        tree[tempnum]=temp;
        point next;//将除起始点外的所有点按对起始点的极角排序，取出极角相同点 
        long num=1,judge;
        double multi;
        for(i=2;i<n;i++){
            judge=0;
            next=tree[i];
            for(j=num;j>=1;j--){
                multi=(next.x-tree[0].x)*(tree[j].y-tree[0].y);
                multi-=(tree[j].x-tree[0].x)*(next.y-tree[0].y);
                if(multi>0){
                    tree[j+1]=tree[j];
                    continue;
                }
                else if(multi<0) break;
                else{
                    double len1,len2;
                    len1=pow(next.x-tree[0].x,2)+pow(next.y-tree[0].y,2);
                    len2=pow(tree[j].x-tree[0].x,2)+pow(tree[j].y-tree[0].y,2);
                    if(len1>len2) tree[j]=next;
                    num--;
                    judge=1;
                    for(;j<=num;j++) tree[j]=tree[j+1];
                    break;
                }
            }
            if(judge==0){
                tree[j+1]=next;
                num++;
            }
        }
        //cout<<"************"<<endl;
        //for(i=0;i<=num;i++) cout<<tree[i].x<<" "<<tree[i].y<<endl;
        //cout<<"************"<<endl;
        point* stk=new point[num+1];
        long top=2;
        for(i=0;i<3;i++) stk[i]=tree[i];
        for(i=3;i<=num;i++){
            while(1){
                multi=(stk[top].x-stk[top-1].x)*(tree[i].y-stk[top-1].y);
                multi-=(tree[i].x-stk[top-1].x)*(stk[top].y-stk[top-1].y);
                if(multi>=0){
                    stk[++top]=tree[i];
                    break;
                }
                else top--;
            }
        }
        len=0;
        for(i=1;i<=top;i++){
            len+=sqrt(pow(stk[i].x-stk[i-1].x,2)+pow(stk[i].y-stk[i-1].y,2));
        }
        len+=sqrt(pow(stk[0].x-stk[top].x,2)+pow(stk[0].y-stk[top].y,2));
        printf("%.2f\n",len);
        delete []tree;
        delete []stk;
    }
    return 0;
}
                    
                        
                
                
         
        
        
            
    
    
