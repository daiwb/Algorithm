#include <iostream>
#include <cstring>
using namespace std;

long f(long n,long m){
	double num=1;
	long i;
	for(i=1;i<=n-m;i++)
		num=num*(double)(m+i)/(double)i;
	return (long)num;
}

int main(void){
	char a[5];
	char temp;
	long num,i,j,len;
	while(cin>>a){
		num=1;
		len=strlen(a);
		if(len==1){
			cout<<(long)(a[0]-96)<<endl;
			continue;
		}
		for(i=1;i<len;i++)
			if(a[i]<=a[i-1]){
				num=0;
				break;
			}
		if(num==0){
			cout<<num<<endl;
			continue;
		}
		num=0;
		for(i=1;i<len;i++)
			num+=f(26,i);
		temp=0;
		for(i=0;i<len-1;i++){
			for(j=temp+1;j<a[i]-96;j++){
				num+=f(26-j,len-i-1);
			}
			temp=a[i]-96;
		}
		num+=a[len-1]-a[len-2];
		cout<<num<<endl;
	}
	return 0;
}

		

