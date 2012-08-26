/*
zju 1139 Rectangles
00:04.86 472k
2004.07.25 by adai
*/

#include <stdio.h>

class point{
public:
	int xmin;
	int xmax;
	int ymin;
	int ymax;
};

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		point* r=new point[n];
		for(int i=0;i<n;i++) scanf("%d %d %d %d",&r[i].xmin,&r[i].xmax,&r[i].ymin,&r[i].ymax);
		
		int num=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j==i) continue;
				if(r[i].xmin>=r[j].xmin&&
					r[i].xmin<=r[j].xmax&&
					r[i].xmax>=r[j].xmin&&
					r[i].xmax<=r[j].xmax&&
					r[i].ymin>=r[j].ymin&&
					r[i].ymin<=r[j].ymax&&
					r[i].ymax>=r[j].ymin&&
					r[i].ymax<=r[j].ymax){
					num++;
					break;
				}
			}
		}

		printf("%d\n",num);

		delete []r;
	}
	return 0;
}
