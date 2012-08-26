/*ZJU1978 Assistance Required
2004.04.08 By adai
00:00.06 660K*/

#include <iostream>
#include <cstdio>
using namespace std;

struct p{
	long value;			//value
	struct p *next;		//next
};
p b[35000];
p* head;

long a[3001],i,j,kase(1);

void init(void){
	for(i=0;i<34999;i++){
		b[i].value=i+2;
		b[i].next=&b[i+1];
	}
	b[34999].value=34501;
	b[34999].next=NULL;
	head=&b[0];
}

void compute(void){
	while(kase<3001){
		a[kase++]=(*head).value;
		long tv=(*head).value;
		p* tnext=head;
		long sign=1;
		while((*tnext).next){
			for(i=0;i<tv-1;i++){
				tnext=(*tnext).next;
				if((*tnext).next==NULL){
					sign=0;
					break;
				}
			}
			if(sign==0) break;
			p* ttnext;
			ttnext=(*tnext).next;
			ttnext=(*ttnext).next;
			(*tnext).next=ttnext;
		}
		head=(*head).next;
	}
}

int main(){
	long n;
	init();
	compute();
	while(scanf("%ld",&n)&&n!=0) printf("%ld\n",a[n]);
	return 0;
}