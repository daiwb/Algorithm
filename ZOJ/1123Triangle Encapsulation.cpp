/*
zju 1123 Triangle Encapsulation
00:00.01 444k
*/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

const double eps=1e-8;
double area;

int printrow[19];
int print[19][19];


class point{
public:
	double x;
	double y;
	point(){}
}p[3];

double dis(point a,point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

double getarea(point a,point b,point c){
	double len1=dis(a,b);
	double len2=dis(b,c);
	double len3=dis(a,c);
	double s=(len1+len2+len3)/2;
	return sqrt(s*(s-len1)*(s-len2)*(s-len3));
}

bool isintriangle(point a){
	double totalarea(0),temp;
	
	temp=getarea(a,p[1],p[2]);
	if(temp<eps) return 0;
	totalarea+=temp;
	temp=getarea(p[0],a,p[2]);
	if(temp<eps) return 0;
	totalarea+=temp;
	temp=getarea(p[0],p[1],a);
	if(temp<eps) return 0;
	totalarea+=temp;

	if(fabs(totalarea-area)<eps) return 1;
	return 0;
}

int main(){
	cout<<"Program 4 by team X"<<endl;

	while(1){
		cin>>p[0].x>>p[0].y>>p[1].x>>p[1].y>>p[2].x>>p[2].y;
		if(cin.fail()) break;

		area=getarea(p[0],p[1],p[2]);

		memset(printrow,-1,sizeof(printrow));
		memset(print,0,sizeof(print));

		int left=19;

		point temp;
		for(int i=0;i<19;i++){
			for(int j=0;j<19;j++){
				temp.x=j-9;
				temp.y=9-i;
				if(isintriangle(temp)){
					print[i][j]=1;
					if(j<left) left=j;
					if(j>printrow[i]) printrow[i]=j;
				}
			}
		}

		for(int i=0;i<19;i++){
			if(printrow[i]==-1) continue;
			int sign=0;
			int right=printrow[i];
			for(int j=left;j<=right;j++){
				if(sign){
					cout<<" ";
				}
				sign=1;
				if(print[i][j]){
					printf("(%2d,%3d)",j-9,9-i);
				}
				else{
					printf("        ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	cout<<"End of program 4 by team X"<<endl;
	return 0;
}
