#include<iostream>
using namespace std;

int main(void){
	int n,m,i,j,count,len;
	while(cin>>n&&n!=0){
		for(m=2;;m++){
			int* bul=new int[n];
			for(i=0;i<n;i++)
				bul[i]=0;
			count=0;
			bul[count]=1;
			len=1;
			for(;;){
				for(j=1;j<=m;j++){
					count++;
					if(count==n) count=0;
					while(bul[count]==1){
						count++;
						if(count>=n) count%=n;
					}
				}
				bul[count]=1;
				len++;
				if(bul[1]==1) break;
			}
			if(len==n){
				cout<<m<<endl;
				delete []bul;
				break;
			}			
		}
	}
	return 0;
}

