#include <iostream>
using namespace std;

int g(int a)
{
	if(a==0) return 1;
	else return a*g(a-1);
}
int f(int a,int b)
{
	return g(a)/g(b)/g(a-b);
}

int main(void)
{
	int n,i,num,total,p,a[20],b[10000];
	while(cin>>n){
		for(i=0;i<10000;i++)
			b[i]=0;
		total=0;
		num=1;
		for(i=0;i<n;i++){
			cin>>a[i];
			total+=a[i];
			b[a[i]]++;
		}
		p=total;
		for(i=0;i<n;i++){
			num*=f(p,a[i]);
			p-=a[i];
		}
		for(i=0;i<total;i++){
			if(b[i]!=0) num/=g(b[i]);
		}
		cout<<num<<endl;
	}
	return 0;
}