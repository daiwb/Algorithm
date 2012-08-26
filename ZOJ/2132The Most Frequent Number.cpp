//zju 2132 The Most Frequent Number

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	while(1){
		cin>>n;
		if(cin.fail()) break;
		vector<int> a;
		vector<int> b;
		int index=0;
		int i,t,s;
		int sign=0;
		int num,half;
		half=(n+1)/2;
		for(t=0;t<n;t++){
			cin>>s;
			if(sign) continue;
			for(i=0;i<index;i++){
				if(a[i]==s){
					b[i]++;
					break;
				}
			}
			if(i==index){
				a.push_back(s);
				b.push_back(1);
				index++;
			}
			if(b[i]>=half){
				num=a[i];
				sign=1;
			}
		}
		for(i=0;i<index;i++){
			if(b[i]>=half){
				num=a[i];
				break;
			}
		}
		cout<<num<<endl;
		//delete []a;
		//delete []b;
	}
	return 0;
}