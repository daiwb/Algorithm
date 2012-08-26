/*
ZJU 1460 The Partition of a Cake
00:00.11 440K
*/

#include <iostream>
using namespace std;

class cutline
{
public:
	double x1;
	double y1;
	double x2;
	double y2;
}cut[8];

class point
{
public:
	double x;
	double y;
}intersection[7];

double absolute(double a,double b)
{
	if(a<b) return b-a;
	return a-b;
}

int same(int a,int b) 
{ 
	int x1,x2,x3,x4,y1,y2,y3,y4; 
	x1=cut[a].x1;
	y1=cut[a].y1;
	x2=cut[a].x2;
	y2=cut[a].y2; 
	x3=cut[b].x1;
	y3=cut[b].y1;
	x4=cut[b].x2;
	y4=cut[b].y2; 
	return (y3-y1)*(x2-x1)-(x3-x1)*(y2-y1)==0&&(y4-y1)*(x2-x1)-(x4-x1)*(y2-y1)==0; 
} 

int main()
{
	int n;			//the number of the cutting
	int cake;		//num of cakes after cutting
	int interno;	//num of intersection
	double eps=1e-10;
	int sign;
	int i,j,t;
	double x,y;
	while(cin>>n&&n!=0)
	{		
		//input
		for(i=0;i<n;i++)
		{
			cin>>cut[i].x1>>cut[i].y1>>cut[i].x2>>cut[i].y2;
			for(j=0;j<i;j++)
			{
				if(same(i,j)) i--,n--;
			}
		}
		
		cake=1+n;
		
		for(i=0;i<n;i++)
		{
			interno=0;
			for(j=i+1;j<n;j++)
			{
				int denominator; 
				int molecule1,molecule2; 
				int x1,x2,x3,x4,y1,y2,y3,y4;
				x1=cut[i].x1;
				y1=cut[i].y1;
				x2=cut[i].x2;
				y2=cut[i].y2; 
				x3=cut[j].x1;
				y3=cut[j].y1;
				x4=cut[j].x2;
				y4=cut[j].y2; 
				denominator = (x2-x1)*(y4-y3) - (x4-x3)*(y2-y1); 
				molecule1 = (y4-y3)*x4*(x2-x1) - (y2-y1)*x2*(x4-x3) - (x4-x3)*(x2-x1)*(y4-y2); 
				molecule2 = (x4-x3)*y4*(y2-y1) - (x2-x1)*y2*(y4-y3) - (y4-y3)*(y2-y1)*(x4-x2); 
				x = (double)(molecule1) / (double)(denominator); 
				y = (double)(molecule2) / (double)(-denominator); 
				if(x>=1000||x<=0||y>=1000||y<=0) continue;
				sign=0;
				for(t=0;t<interno;t++)
				{
					if(x==intersection[t].x&&y==intersection[t].y)
					{
						sign=1;
						break;
					}
				}
				if(sign==0)
				{
					intersection[interno].x=x;
					intersection[interno].y=y;
					interno++;
				}
			}
			cake+=interno;
		}
		//output
		cout<<cake<<endl;
	}
	return 0;
}