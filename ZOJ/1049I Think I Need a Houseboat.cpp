#define pi 3.1415926
#include <iostream>
using namespace std;

int main(void)
{
	int i,n,year;
	float x,y;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		year=(int)(pi*(x*x+y*y)/100)+1;
		cout<<"Property "<<i+1<<": This property will begin eroding in year "<<year<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
}