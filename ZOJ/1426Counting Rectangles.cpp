/*
zju 1426 Counting Rectangles
00:00.00 456k
2004.07.19 by adai
*/

#include <iostream>
#include <cstdio>
using namespace std;

class segment{
public:
	int x1;
	int y1;
	int x2;
	int y2;
}lineh[100],linev[100];

class intersect{
public:
	int x;
	int y;
	int h;
	int v;
}point[4950];

int judge(int i,int j,int t,int s){
	if(point[i].x==point[j].x){
		if(point[i].v!=point[j].v) return 0;
		if(point[t].x!=point[s].x) return 0;
		if(point[t].v!=point[s].v) return 0;
		if(point[i].y==point[t].y){
			if(point[i].h!=point[t].h) return 0;
			if(point[j].y!=point[s].y) return 0;
			if(point[j].h!=point[s].h) return 0;
			return 1;
		}
		else if(point[i].y==point[s].y){
			if(point[i].h!=point[s].h) return 0;
			if(point[j].y!=point[t].y) return 0;
			if(point[j].h!=point[t].h) return 0;
			return 1;
		}
		return 0;
	}
	else if(point[i].x==point[t].x){
		if(point[i].v!=point[t].v) return 0;
		if(point[j].x!=point[s].x) return 0;
		if(point[j].v!=point[s].v) return 0;
		if(point[i].y==point[j].y){
			if(point[i].h!=point[j].h) return 0;
			if(point[t].y!=point[s].y) return 0;
			if(point[t].h!=point[s].h) return 0;
			return 1;
		}
		else if(point[i].y==point[s].y){
			if(point[i].h!=point[s].h) return 0;
			if(point[t].y!=point[j].y) return 0;
			if(point[t].h!=point[j].h) return 0;
			return 1;
		}
		return 0;
	}
	else if(point[i].x==point[s].x){
		if(point[i].v!=point[s].v) return 0;
		if(point[j].x!=point[t].x) return 0;
		if(point[j].v!=point[t].v) return 0;
		if(point[i].y==point[j].y){
			if(point[i].h!=point[j].h) return 0;
			if(point[s].y!=point[t].y) return 0;
			if(point[s].h!=point[t].h) return 0;
			return 1;
		}
		else if(point[i].y==point[t].y){
			if(point[i].h!=point[t].h) return 0;
			if(point[s].y!=point[j].y) return 0;
			if(point[s].h!=point[j].h) return 0;
			return 1;
		}
		return 0;
	}
	return 0;
}

int main(){
	int kase;
	int numh,numv,nump;		//num of horizontal and vertical segments and intersecting points
	int x1,y1,x2,y2;
	int i,j,t,s;
	scanf("%d",&kase);
	int n;
	while(kase--){
		scanf("%d",&n);
		numh=numv=nump=0;
		for(i=0;i<n;i++){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			if(x1==x2){	//vertical
				if(y1>y2){
					int temp=y1;
					y1=y2;
					y2=temp;
				}
				linev[numv].x1=x1;
				linev[numv].x2=x2;
				linev[numv].y1=y1;
				linev[numv].y2=y2;
				numv++;
				for(j=0;j<numh;j++){
					if(lineh[j].y1>=y1&&lineh[j].y1<=y2&&x1>=lineh[j].x1&&x1<=lineh[j].x2){
						point[nump].x=x1;
						point[nump].y=lineh[j].y1;
						point[nump].h=j;
						point[nump].v=numv-1;
						nump++;
					}
				}
			}
			else if(y1==y2){	//horizontal
				if(x1>x2){
					int temp=x1;
					x1=x2;
					x2=temp;
				}
				lineh[numh].x1=x1;
				lineh[numh].x2=x2;
				lineh[numh].y1=y1;
				lineh[numh].y2=y2;
				numh++;
				for(j=0;j<numv;j++){
					if(linev[j].x1>=x1&&linev[j].x1<=x2&&y1>=linev[j].y1&&y1<=linev[j].y2){
						point[nump].x=linev[j].x1;
						point[nump].y=y1;
						point[nump].h=numh-1;
						point[nump].v=j;
						nump++;
					}
				}
			}
		}
		//for(i=0;i<nump;i++){
		//	cout<<"x="<<point[i].x<<" y="<<point[i].y<<" h="<<point[i].h<<" v="<<point[i].v<<endl;
		//}
		int num=0;
		for(i=0;i<nump-3;i++){
			for(j=i+1;j<nump-2;j++){
				for(t=j+1;t<nump-1;t++){
					for(s=t+1;s<nump;s++){
						num+=judge(i,j,t,s);
					}
				}
			}
		}
		printf("%d\n",num);
	}
	return 0;
}