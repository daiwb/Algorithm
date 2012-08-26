#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int Judge(int a,int b)
{
	for(int i=2;i<=a&&i<=b;i++)
		if(a%i==0&&b%i==0) return 0;
	return 1;
}

int main(void)
{
	int n,count,num;
	int i,j;
	int a[50];
	cin>>n;
	while(n!=0){
		for(i=0;i<n;i++)
			cin>>a[i];
		count=0;
		num=0;
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++){
				num++;
				if(Judge(a[i],a[j])==1) count++;
			}
		if(count==0) cout<<"No estimate for this data set."<<endl;
		else cout<<setiosflags(ios::fixed)<<setprecision(6)<<sqrt(6*(double)num/(double)count)<<endl;
		cin>>n;
	}
	return 0;
}



