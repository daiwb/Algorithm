#include<iostream>
using namespace std;

int main(void){
	double c,len,n;
	while(cin>>c&&c!=0.00){
		len=0;
		for(n=1;;n++){
			len+=1/(n+1);
			if(len>=c) break;
		}
		cout<<(long)n<<" card(s)"<<endl;
	}
	return 0;
}