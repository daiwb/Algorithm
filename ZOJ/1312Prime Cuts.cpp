#include <iostream>
using namespace std;

int main(void)
{
	long n,c,i,j,total;
	while(cin>>n>>c){
		long* num=new long[n+1];
		long* ans=new long[n+1];
		for(i=0;i<=n;i++)
			num[i]=0;
		ans[1]=1;
		total=1;
		for(i=2;i<=n;i++)
			if(num[i]==0){
				for(j=2;i*j<=n;j++)
					num[i*j]=1;
				ans[++total]=i;
			}
		if((total%2==0&&2*c>total)||(total%2==1&&2*c-1>total)){
			cout<<n<<" "<<c<<":";
			for(i=1;i<=total;i++)
				cout<<" "<<ans[i];
			cout<<endl<<endl;
		}
		else if(total%2==0){
			cout<<n<<" "<<c<<":";
			for(i=total/2-c+1;i<=total/2+c;i++)
				cout<<" "<<ans[i];
			cout<<endl<<endl;
		}
		else if(total%2==1){
			cout<<n<<" "<<c<<":";
			for(i=(total-2*c+3)/2;i<=(total+2*c-1)/2;i++)
				cout<<" "<<ans[i];
			cout<<endl<<endl;
		}
		delete []num;
		delete []ans;
	}
	return 0;
}