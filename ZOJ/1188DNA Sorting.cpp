#include<iostream>
using namespace std;

int main(void){
	long d,i,j,n,m,t,p,q,max;
	char dna[110][55];
	cin>>d;
	for(i=0;i<d;i++){
		if(i) cout<<endl;
		max=0;		
		cin>>n>>m;
		long* sort=new long[m];
		for(j=0;j<m;j++)
			sort[j]=0;
		for(j=0;j<m;j++)
			cin>>dna[j];
		for(t=0;t<m;t++){
			for(p=0;p<n-1;p++){
				for(q=p+1;q<n;q++){
					if(dna[t][q]<dna[t][p]) sort[t]++;
				}
			}
			if(sort[t]>max) max=sort[t];
		}
		for(p=0;p<=max;p++){
			for(q=0;q<m;q++){
				if(sort[q]==p) cout<<dna[q]<<endl;
			}
		}
		delete []sort;
	}
	return 0;
}


