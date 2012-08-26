#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Curve{
	double x;
	double y;
	struct Curve *next;
}point[16385];

int main(void)
{
	int i,n,num;
	struct Curve *fp;
	double sx,sy,dx,dy;
	while(cin>>n){
		cin>>sx>>sy>>dx>>dy;
		num=0;
		point[num].x=sx;
		point[num].y=sy;
		point[num].next=&point[num+1];
		num++;
		point[num].x=dx;
		point[num].y=dy;
		point[num].next=NULL;
		num++;
		for(i=1;i<=n;i++){
			for(fp=&point[0];fp->next!=NULL;){
				point[num].x=(*fp).x+2*((*(*fp).next).x-(*fp).x)/3;
				point[num].y=(*fp).y+2*((*(*fp).next).y-(*fp).y)/3;
				point[num].next=(*fp).next;
				num++;
				point[num].x=(*fp).x+((*(*fp).next).x-(*fp).x)/3;
				point[num].y=(*fp).y+((*(*fp).next).y-(*fp).y)/3;
				point[num].next=&point[num+1];
				num++;
				point[num].x=(point[num-1].x+point[num-2].x-sqrt(3)*(point[num-2].y-point[num-1].y))/2;
				point[num].y=(point[num-1].y+point[num-2].y+sqrt(3)*(point[num-2].x-point[num-1].x))/2;
				point[num].next=&point[num-2];
				num++;
				(*fp).next=&point[num-2];
				fp=point[num-3].next;
			}
		}
		for(fp=&point[0];fp!=NULL;fp=(*fp).next)
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<(*fp).x<<" "<<(*fp).y<<endl;
		cout<<"\n";
	}
	return 0;
}
				




		

