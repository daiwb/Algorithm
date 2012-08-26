//zju 1008 Gnome Tetravex

#include <stdio.h> 

int kase=0;				//Game index 
int n=0;				//Puzzle size 
int num=0;				//How many different types of squares 
int square[25][4];		//Source squares 
int count[25];			//Quantity of a certain type of squares 
int table[25];			//Solution 
int n2;					//n*n

int place(int pos) 
{ 
	int i; 
	if(pos==n2) return 1; 
	
	for(i=0; i<num; i++) 
	{ 
		if(count[i]==0) continue; 
		
		if(pos%n!=0){
			if(square[table[pos-1]][1]!=square[i][3]) continue; 
		}
		
		if(pos/n!=0){
			if(square[table[pos-n]][2]!=square[i][0]) continue; 
		}
		table[pos]=i; 
		count[i]--; 
		if(place(pos+1)==1) return 1; 
		count[i]++; 
	} 
	return 0; 
} 

int main() 
{ 
	int i, j; 
	int t, r, b, l;   //Temporary variables for input (top, right, bottom, left) 
	while(1) 
	{ 
		scanf("%d", &n); 
		if(n==0) break; 
		num=0; 
		n2=n*n;
		for(i=0; i<n2; i++) 
		{ 
			scanf("%d %d %d %d", &t, &r, &b, &l); 
			j=0; 
			while(j<num) 
			{ 
				if(square[j][0]==t && square[j][1]==r && square[j][2]==b && square[j][3]==l) 
				{ 
					count[j]++; 
					break; 
				} 				
				j++; 
			} 
			if(j==num) 
			{ 
				square[j][0]=t; 
				square[j][1]=r; 
				square[j][2]=b; 
				square[j][3]=l; 
				count[j]=1; 
				num++; 
			} 
		} 
		if(kase++) 
			printf("\n"); 
		if(place(0)==1) printf("Game %d: Possible\n", kase); 
		else printf("Game %d: Impossible\n", kase); 
	} 
	return 0; 
}
