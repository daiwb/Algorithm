/*
ZJU 1149 Dividing up
2004.05.03 By adai
00:00.00 380K
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
	long num[6];
	long val,i,count=1,jug,sum,j1,j2,j3,j4,j5,j6;
	while(scanf("%ld %ld %ld %ld %ld %ld",&num[0],&num[1],&num[2],&num[3],&num[4],&num[5])!=EOF){
		if(num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0) break;
		jug=0;
		val=0;
		for(i=0;i<6;i++){
			while(num[i]>6) num[i]-=6;
		}
		for(i=0;i<6;i++)
			val+=(i+1)*num[i];
		if(val%2==1){
			printf("Collection #%ld:\n",count++);
			//cout<<"Collection #"<<count++<<":"<<endl;
			printf("Can't be divided.\n\n");
			//cout<<"Can't be divided."<<endl<<endl;
			continue;
		}
		else{
			val/=2;
			for(j1=0;j1<=num[0];j1++){
				if(1*j1>val||jug==1) break;
				for(j2=0;j2<=num[1];j2++){
					if(1*j1+2*j2>val||jug==1) break;
					for(j3=0;j3<=num[2];j3++){
						if(1*j1+2*j2+3*j3>val||jug==1) break;
						for(j4=0;j4<=num[3];j4++){
							if(1*j1+2*j2+3*j3+4*j4>val||jug==1) break;
							for(j5=0;j5<=num[4];j5++){
								if(1*j1+2*j2+3*j3+4*j4+5*j5>val||jug==1) break;
								for(j6=0;j6<=num[5];j6++){
									sum=1*j1+2*j2+3*j3+4*j4+5*j5+6*j6;
									if(sum==val){
										jug=1;
										break;
									}
								}
							}
						}
					}
				}
			}
			printf("Collection #%ld:\n",count++);
			//cout<<"Collection #"<<count++<<":"<<endl;
			if(jug==1) printf("Can be divided.\n\n");
			else printf("Can't be divided.\n\n");
		}
	}
	return 0;
}
			
