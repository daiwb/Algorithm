//zju 1596 Hamming Problem

#include<iostream> 
#include<vector> 
using namespace std; 

int main() 
{ 
	int p1,p2,p3,i,n; 
	long long a,b,c,min; 
	vector<long long> sp; 
	while(cin>>a>>b>>c>>n) 
	{ 
		p1=p2=p3=0; 
		sp.resize(1); 
		sp[0]=1; 
		for(i=1;i<=n;i++) 
		{ 
			min=sp[p1]*a; 
			if(min>sp[p2]*b)min=sp[p2]*b; 
			if(min>sp[p3]*c)min=sp[p3]*c; 
			sp.push_back(min); 
			while(sp[p1]*a<=min)p1++; 
			while(sp[p2]*b<=min)p2++; 
			while(sp[p3]*c<=min)p3++; 
		} 
		cout<<sp[n]<<endl; 
	} 
	return 0; 
}