//zju 2099 Frame Polygonal Line

#include <iostream>
using namespace std;

int main(){
	long x,y;
	while(cin>>x>>y){
		if(x==0&&y==0) break;
		long maxx,minx,maxy,miny;
		maxx=minx=x;
		maxy=miny=y;
		while(cin>>x>>y){
			if(x==0&&y==0){
				cout<<minx<<" "<<miny<<" "<<maxx<<" "<<maxy<<endl;
				break;
			}
			if(x<minx) minx=x;
			if(x>maxx) maxx=x;
			if(y<miny) miny=y;
			if(y>maxy) maxy=y;
		}
	}
	return 0;
}