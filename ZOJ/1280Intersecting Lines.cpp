#include<iostream>
#include<iomanip>
using namespace std;

int main(void){
	int n,i;
	double x1,y1,x2,y2,x3,y3,x4,y4,x,y;
	cin>>n;
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	for(i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		if((y2-y1)*(x4-x3)==(x2-x1)*(y4-y3)){
			if((y2-y1)*(x3-x1)==(x2-x1)*(y3-y1)) cout<<"LINE"<<endl;
			else cout<<"NONE"<<endl;
		}
		else{
			if(x1==x2){
				x=x1;
				y=y3+(y4-y3)*(x-x3)/(x4-x3);
			}
			else if(x3==x4){
				x=x3;
				y=y1+(y2-y1)*(x-x1)/(x2-x1);
			}
			else{
				x=((y3-y1)*(x4-x3)*(x2-x1)+x1*(y2-y1)*(x4-x3)-x3*(y4-y3)*(x2-x1))/((y2-y1)*(x4-x3)-(y4-y3)*(x2-x1));
				y=y1+(y2-y1)*(x-x1)/(x2-x1);
			}
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<"POINT "<<x<<" "<<y<<endl;
		}
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}


