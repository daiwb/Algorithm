#include <iostream>
#include <string>

using namespace std;

int main(void){
	char a[20];
	char b;
	int count=0,mile;
	while(1){
		cin>>a;
		if(strcmp(a,"#")==0) break;
		if(strcmp(a,"0")==0){
			cout<<count<<endl;
			count=0;
		}
		else{
			cin>>a;
			cin>>mile;
			cin>>b;
			if(b=='Y'){
				if(mile<500) count+=500;
				else count+=mile;
			}
			else if(b=='B'){
				count+=mile*1.5;
			}
			else count+=mile*2;
		}
	}
	return 0;
}
