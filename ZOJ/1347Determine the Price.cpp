//ZJU 1347 Determine the Price
//2003.09.18 BY adai

#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	long d,i,j,n,m,root1,root2,audience;
	double p,r,s,price,revenue;
	cin>>d;
	for(i=0;i<d;i++){
		if(i) cout<<endl;
		cin>>n>>p>>m>>r>>s;
		root1=(p*n-m*(p-0.01-s))/(2*m*p);
		root2=root1+1;
		if((root1*p+p-0.01-s)*(n-m*root1)>=(root2*p+p-0.01-s)*(n-m*root2)) j=root1;
		else j=root2;
		price=p*j+p-0.01;
		audience=n-m*j;
		revenue=(price-s)*audience-r;
		cout<<"price = "<<setiosflags(ios::fixed)<<setprecision(2)<<price<<endl;
		cout<<"audiences = "<<audience<<endl;
		cout<<"revenue = "<<setiosflags(ios::fixed)<<setprecision(2)<<revenue<<endl;
	}
	return 0;
}
		
