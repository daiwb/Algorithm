//zju 2131 Bejewlled

#include <iostream>
using namespace std;

char mat[8][9];
char temp[8][8];
int sign[8][8];
int num;
int total;

int changeh(int s,int e){
	if(mat[s][e]==mat[s][e+1]) return 0;
	int i,j,t;
	total=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			temp[i][j]=mat[i][j];
			sign[i][j]=0;
		}
	}
	temp[s][e+1]=mat[s][e];
	temp[s][e]=mat[s][e+1];

	for(i=0;i<=7;i++){
		for(j=0;j<=5;j++){
			if(temp[i][j]==temp[i][j+1]&&temp[i][j+1]==temp[i][j+2]){
				for(t=j;t<=7;t++){
					if(temp[i][t]==temp[i][j]){
						if(sign[i][t]==0){
							total++;
							sign[i][t]=1;
						}
					}
					else{
						j=t-1;
						break;
					}
				}
			}
		}
	}

	for(j=0;j<=7;j++){
		for(i=0;i<=5;i++){
			if(temp[i][j]==temp[i+1][j]&&temp[i+1][j]==temp[i+2][j]){
				for(t=i;t<=7;t++){
					if(temp[t][j]==temp[i][j]){
						if(sign[t][j]==0){
							total++;
							sign[t][j]=1;
						}
					}
					else{
						i=t-1;
						break;
					}
				}
			}
		}
	}
	if(total>num) num=total;
	return 0;
}

int changev(int s,int e){
	if(mat[s][e]==mat[s+1][e]) return 0;
	int i,j,t;
	total=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			temp[i][j]=mat[i][j];
			sign[i][j]=0;
		}
	}
	temp[s+1][e]=mat[s][e];
	temp[s][e]=mat[s+1][e];

	for(i=0;i<=7;i++){
		for(j=0;j<=5;j++){
			if(temp[i][j]==temp[i][j+1]&&temp[i][j+1]==temp[i][j+2]){
				for(t=j;t<=7;t++){
					if(temp[i][t]==temp[i][j]){
						if(sign[i][t]==0){
							total++;
							sign[i][t]=1;
						}
					}
					else{
						j=t-1;
						break;
					}
				}
			}
		}
	}

	for(j=0;j<=7;j++){
		for(i=0;i<=5;i++){
			if(temp[i][j]==temp[i+1][j]&&temp[i+1][j]==temp[i+2][j]){
				for(t=i;t<=7;t++){
					if(temp[t][j]==temp[i][j]){
						if(sign[t][j]==0){
							total++;
							sign[t][j]=1;
						}
					}
					else{
						i=t-1;
						break;
					}
				}
			}
		}
	}
	if(total>num) num=total;
	return 0;
}

int main(){
	int i,j;
	while(1){
		for(i=0;i<8;i++) cin>>mat[i];
		if(cin.fail()) break;
		num=0;
		
		for(i=0;i<=7;i++){
			for(j=0;j<=6;j++){
				changeh(i,j);
			}
		}
		for(j=0;j<=7;j++){
			for(i=0;i<=6;i++){
				changev(i,j);
			}
		}
		cout<<num<<endl;
	}
	return 0;
}
