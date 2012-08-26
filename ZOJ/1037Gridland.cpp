/*ZJU 1037 Gridland
2004.04.22 By adai
00:00.10 444K*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	long kase,count;
	cin>>count;
	for(kase=1;kase<=count;kase++){
		long row,col;
		double len;
		cin>>row>>col;
		if(row%2==1&&col%2==1) len=row*col-1+sqrt(2);
		else len=row*col;
		cout<<"Scenario #"<<kase<<":"<<endl;
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<len<<endl<<endl;
	}
	return 0;
}
