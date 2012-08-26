/*
ZJU 1025 Wooden Sticks
2004.05.04 By adai
00:00.02 480K
*/

#include <iostream>
#include <cstdio>
using namespace std;

class w_stick{
public:
	long l,w;	//length,weight
}stick[5001];
bool sign[5001];

void swap(long i,long j,w_stick temp){
	temp.l=stick[i].l;
	temp.w=stick[i].w;
	stick[i].l=stick[j].l;
	stick[i].w=stick[j].w;
	stick[j].l=temp.l;
	stick[j].w=temp.w;
}

void quicksort(long left,long right){
	long i,j,pl,pw;
	w_stick temp;
	if(left<right){
		i=left;
		j=right+1;
		pl=stick[left].l;
		pw=stick[left].w;
		do{
			do{
				i++;
			}while(stick[i].l<pl||(stick[i].l==pl&&stick[i].w<pw));
			do{
				j--;
			}while(stick[j].l>pl||(stick[j].l==pl&&stick[j].w>pw));
			if(i<j)
				swap(i,j,temp);
		}while(i<j);
		swap(left,j,temp);
		quicksort(left,j-1);
		quicksort(j+1,right);
	}
}

int main(){
	long kase,n,i,j,sum,temp;
	cin>>kase;
	while(kase--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>stick[i].l>>stick[i].w;
		quicksort(1,n);
		sum=0;
		for(i=1;i<=n;i++) sign[i]=0;
		for(i=1;i<=n;i++){
			if(sign[i]==0){
				sum++;
				temp=stick[i].w;
				for(j=i+1;j<=n;j++){
					if(sign[j]==0){
						if(stick[j].w>=temp){
							sign[j]=1;
							temp=stick[j].w;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}