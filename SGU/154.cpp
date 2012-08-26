//Factorial

#include <iostream>
#include <cmath>

using namespace std;

long sum(long i){
	long total=0;
	while(i>=1){
		total+=i;
		i/=5;
	}
	return total;
}

int main(void){
	long q,temp,m,i=0;
	cin>>q;
	if(q==0){
		cout<<1<<endl;
		return 0;
	}
	temp=q;
	while(temp>=1){
		m=(long)(log10(temp*4+1)/log10(5))-1;
		i+=(long)pow(5,m);
		temp-=((long)pow(5,m+1)-1)/4;
	}
	if(sum(i)!=q) cout<<"No solution"<<endl;
	else cout<<i*5<<endl;
	return 0;
}
