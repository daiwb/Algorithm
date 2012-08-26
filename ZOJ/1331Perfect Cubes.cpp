#include <stdio.h>
int main(void)
{
	int a,b,c,d;
	for(a=6;a<=200;a++){
		for(b=2;;b++){
			for(c=b;;c++){
				for(d=c;;d++){
					if(b*b*b+c*c*c+d*d*d==a*a*a) printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					if(b*b*b+c*c*c+d*d*d>a*a*a){
						d=2;
						break;
						}
					}
				if(b*b*b+c*c*c+d*d*d>a*a*a){
					c=2;
					break;
					}
				}
			if(b*b*b+c*c*c+d*d*d>a*a*a) break;
			}
		}
}
