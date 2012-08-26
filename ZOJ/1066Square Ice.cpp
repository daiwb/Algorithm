/*
ZJU 1066 Square Ice
00:00.00 440K
2004.07.17 by adai
*/

#include <iostream>
using namespace std;

#define MAXROW 4*11-3
#define MAXCOL 4*11+1

int main()
{
	int m,kase(0);
	int row,col;
	int input[11][11];
	char water[MAXROW][MAXCOL];
	int i,j;
	
	while(1)
	{
		cin>>m;
		if(m==0) break;
		row=4*m-3;
		col=4*m+1;
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++) cin>>input[i][j];
		}
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++) water[i][j]=' ';
		}
		for(i=0;i<row;i+=4)
		{
			for(j=0;j<col;j+=4) water[i][j]='h';
		}
		for(i=2;i<row;i+=4)
		{
			for(j=2;j<col;j+=4) water[i][j]='h';
		}
		for(i=0;i<row;i+=4)
		{
			for(j=2;j<col;j+=4) water[i][j]='o';
		}
				
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(input[i][j]==1){
					water[4*i][4*j+2]='O';
					water[4*i][4*j+2-1]=water[4*i][4*j+2+1]='-';
					water[4*i][4*j+2-2]=water[4*i][4*j+2+2]='H';
				}
				else if(input[i][j]==-1)
				{
					water[4*i][4*j+2]='O';
					water[4*i-1][4*j+2]=water[4*i+1][4*j+2]='|';
					water[4*i-2][4*j+2]=water[4*i+2][4*j+2]='H';
				}
			}
		}

		//handle horizontally
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(water[4*i][4*j+2]=='o'){
					if(water[4*i][4*j+2-2]=='h')
					{
						water[4*i][4*j+2-2]='H';
						water[4*i][4*j+2-1]='-';
					}
					else
					{
						water[4*i][4*j+2+2]='H';
						water[4*i][4*j+2+1]='-';
					}
				}
			}
		}
		
		//handle vertically
		for(j=0;j<m;j++)
		{
			if(water[4*0][4*j+2]=='o')
			{
				water[4*0][4*j+2]='O';
				water[4*0+1][4*j+2]='|';
				water[4*0+2][4*j+2]='H';
			}
		}
		for(j=0;j<m;j++)
		{
			if(water[4*(m-1)][4*j+2]=='o')
			{
				water[4*(m-1)][4*j+2]='O';
				water[4*(m-1)-1][4*j+2]='|';
				water[4*(m-1)-2][4*j+2]='H';
			}
		}
		for(i=1;i<m-1;i++)
		{
			for(j=0;j<m;j++)
			{
				if(water[4*i][4*j+2]=='o'){
					water[4*i][4*j+2]='O';
					if(water[4*i-2][4*j+2]=='h')
					{
						water[4*i-2][4*j+2]='H';
						water[4*i-1][4*j+2]='|';
					}
					else
					{
						water[4*i+2][4*j+2]='H';
						water[4*i+1][4*j+2]='|';
					}
				}
			}
		}
		
		//output
		if(kase++) cout<<endl;
		cout<<"Case "<<kase<<":"<<endl<<endl;
		for(i=0;i<col+2;i++) cout<<"*";
		cout<<endl;
		for(i=0;i<row;i++)
		{
			cout<<"*";
			for(j=0;j<col;j++) cout<<water[i][j];
			cout<<"*"<<endl;
		}
		for(i=0;i<col+2;i++) cout<<"*";
		cout<<endl;
	}
	
	return 0;
}