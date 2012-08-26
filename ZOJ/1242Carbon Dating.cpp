#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	double w,d;
	long year,temp;
	int count=1;
	while(cin>>w>>d&&!(w==0&&d==0)){
		year=log10(810*w/d+0.0)/log10(2.0)*5730;
		if(year<10000){
			temp=year;
			year=year/100*100;
			if(temp%100>=50) year+=100;
		}
		else{
			temp=year;
			year=year/1000*1000;
			if(temp%1000>=500) year+=1000;
		}
		cout<<"Sample #"<<count++<<endl;
		cout<<"The approximate age is "<<year<<" years."<<endl<<endl;
	}
	return 0;
}
		

