/*
zju 1010 Area
00:00.20 480k
2004.07.29 by adai
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAXN 1000

class pos{
public:
	double x;
	double y;
	pos &operator = (const pos &cc){
		x=cc.x;
		y=cc.y;
		return *this;
	}
};

class line{
public:
	pos a;
	pos b;
};

double multi(pos p1,pos p2,pos p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double max(double a,double b){
	return a>b?a:b;
}

double min(double a,double b){
	return a<b?a:b;
}

bool across(line u,line v){
	if(
		(max(u.a.x,u.b.x)>=min(v.a.x,v.b.x))&&
		(max(v.a.x,v.b.x)>=min(u.a.x,u.b.x))&&
		(max(u.a.y,u.b.y)>=min(v.a.y,v.b.y))&&
		(max(v.a.y,v.b.y)>=min(u.a.y,u.b.y))&&
		(multi(v.a,u.b,u.a)*multi(u.b,v.b,u.a)>=0)&&
		(multi(u.a,v.b,v.a)*multi(v.b,u.b,v.a)>=0)
	) return 1;
	else return 0;
}

double getarea(pos p[MAXN],int n){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}

pos p[MAXN];
line l[MAXN];
int n;

int main(){
	int kase=0;
	while(1){
		scanf("%d",&n);
		if(n==0) break;

		for(int i=0;i<n;i++) 
			cin>>p[i].x>>p[i].y;
		for(int i=0;i<n;i++){
			l[i].a=p[i];
			l[i].b=p[(i+1)%n];
		}

		if(kase++) printf("\n");
		printf("Figure %d: ",kase);

		if(n<=2){
			printf("Impossible\n");
			continue;
		}

		int isacross=0;
		for(int i=0;i<n-2;i++){
			for(int j=i+2;j<n;j++){
				if((j+1)%n==i) continue;
				if(across(l[i],l[j])){
					isacross=1;
					break;
				}
			}
			if(isacross) break;
		}
		if(isacross){
			printf("Impossible\n");
			continue;
		}

		double area=getarea(p,n);
		printf("%.2lf\n",area);
	}
	return 0;
}
