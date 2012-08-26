#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void insertion_sort(double list[],int n){
	int i,j;
	double next;
	for(i=1;i<n;i++){
		next=list[i];
		for(j=i-1;j>=0&&next>list[j];j--)
			list[j+1]=list[j];
		list[j+1]=next;
	}
}

int main(void){
	int n,i;
	double temp;
	while(cin>>n){
		double* num=new double[n];
		for(i=0;i<n;i++)
			cin>>num[i];
		insertion_sort(num,n);
		temp=num[0];
		for(i=1;i<n;i++)
			temp=2*sqrt(temp*num[i]);
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<temp<<endl;
		delete []num;
	}
	return 0;
}
		
