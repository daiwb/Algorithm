#include<iostream>
using namespace std;

long IsPal(char num[10000],long length){
	long i;
	if(length%2==0){
		for(i=0;i<length/2;i++)
			if(num[i]!=num[length-1-i]) return 0;
		return 1;
	}
	else{
		for(i=0;i<(length-1)/2;i++)
			if(num[i]!=num[length-1-i]) return 0;
		return 1;
	}
}

int main(void){
	long n,length,i,temp,count,det;
	while(cin>>n&&n!=0){
		det=0;
		long jug[17]={0};
		for(i=2;i<=16;i++){
			count=0;
			char* num=new char[10000];
			temp=n;
			while(temp>=i){
				num[count++]=temp%i;
				temp/=i;
			}
			num[count]=temp%i;
			length=count+1;
			if(IsPal(num,length)){
				det=1;
				jug[i]=1;
			}
			delete []num;
		}
		if(det==0) cout<<"Number "<<n<<" is not a palindrom"<<endl;
		else{
			cout<<"Number "<<n<<" is palindrom in basis";
			for(i=2;i<=16;i++)
				if(jug[i]==1) cout<<" "<<i;
			cout<<endl;
		}
	}
	return 0;
}


				
