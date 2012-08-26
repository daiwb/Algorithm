//zju 2130 5 Spots

#include <iostream>
#include <cstdio>
using namespace std;

char mat[65][65];
char spot[65][65];
int num;
int height,width,h,w;

int main(){
	int i,j,t,s;
	char input[65];
	while(1){
		//scanf("%d %d %d %d",&height,&width,&h,&w);
		cin>>height>>width>>h>>w;
		if(cin.fail()) break;
		for(i=0;i<height;i++){
			//scanf("%s",input);
			cin>>input;
			for(j=0;j<width;j++) mat[i][j]=input[j];
		}
		
		for(i=0;i<h;i++){
			//scanf("%s",input);
			cin>>input;
			for(j=0;j<w;j++) spot[i][j]=input[j];
		}
		
		num=0;
		for(i=0;i<=height-h;i++){
			for(j=0;j<=width-w;j++){
				for(t=0;t<h;t++){
					for(s=0;s<w;s++){
						if(spot[t][s]=='.') continue;
						if(spot[t][s]=='O'){
							if(mat[i+t][j+s]!='O') goto next;
						}
						else{
							if(mat[i+t][j+s]!='X') goto next;
						}
					}
				}
				num++;
next:
				;
			}
		}
		//printf("%d\n",num);
		cout<<num<<endl;
	}
	return 0;
}
