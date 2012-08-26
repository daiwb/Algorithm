#include <iostream>
using namespace std;

int main(void)
{
	int i,j,n,num,people,judge;
	while(cin>>n&&n!=-1){
		people=0;
		for(i=2;i<n;i++){
			judge=0;
			num=n;
			for(j=1;j<=i;j++){
				if((num-1)%i!=0){
					judge=1;
					break;
				}
				num=(num-1)*(i-1)/i;
			}
			if(judge==0){
				if(num%i!=0) judge=1;
			}
			if(judge==0) people=i;
		}
		if(people==0) cout<<n<<" coconuts, no solution"<<endl;
		else cout<<n<<" coconuts, "<<people<<" people and 1 monkey"<<endl;
	}
	return 0;
}

