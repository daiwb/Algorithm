/*ZJU 1539 Lot
2004.04.28 By adai
00:00.31 436K*/

#include <iostream>
using namespace std;

long func(long i){
	if(i==1||i==2) return 0;
	if(i==3) return 1;
	return func(i/2)+func((i+1)/2);
}

int main(){
	long i;
	while(cin>>i) cout<<func(i)<<endl;
	return 0;
}