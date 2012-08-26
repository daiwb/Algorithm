#include <iostream>
using namespace std;

int main(void){
	long s,num,count=1,m,n;
	double t;
	while(cin>>s&&s!=0){
		t=(double)s/2;
		m=s/2;
		n=m+1;
		if(t-m<n-t) s=m;
		else s=n;
		t=(double)s*1.5;
		m=s*1.5;
		n=m+1;
		if(t-m<n-t) s=m;
		else s=n;
		if(s%18600==0) num=s/1860000;
		else num=s/1860000+1;
		cout<<"File #"<<count++<<endl;
		cout<<"John needs "<<num<<" floppies."<<"\n"<<endl;
	}
	return 0;
}
