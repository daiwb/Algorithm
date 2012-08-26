#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(void)
{
	int a,b,c,i=1;
	while(cin>>a>>b>>c&&!(a==0&&b==0&&c==0)){
		if(a==-1){
			if((c*c-b*b)>0) cout<<"Triangle #"<<i++<<"\na = "<<setiosflags(ios::fixed)<<setprecision(3)<<sqrt(pow(c*1.0,2.0)-pow(b*1.0,2.0))<<"\n"<<endl;
			else cout<<"Triangle #"<<i++<<"\nImpossible.\n"<<endl;
		}
		else if(b==-1){
			if((c*c-a*a)>0) cout<<"Triangle #"<<i++<<"\nb = "<<setiosflags(ios::fixed)<<setprecision(3.0)<<sqrt(pow(c*1.0,2.)-pow(a*1.0,2.0))<<"\n"<<endl;
			else cout<<"Triangle #"<<i++<<"\nImpossible.\n"<<endl;
		}
		else if(c==-1) cout<<"Triangle #"<<i++<<setiosflags(ios::fixed)<<setprecision(3)<<"\nc = "<<sqrt(pow(a*1.0,2.0)+pow(b*1.0,2.0))<<"\n"<<endl;
	}
	return 0;
}