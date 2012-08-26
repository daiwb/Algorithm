/*
zju 1093 Monkey and Banana
00:00.00 432k
2004.07.29 by adai
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int num;	//num of different blocks
int maxh;

int block[90][3];
int height[90];

void swap(int& a, int& b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void sort(int& a, int& b, int& c){
	if(a > b) swap(a, b);
	if(a > c) swap(a, c);
	if(b > c) swap(b, c);
}

void standardize(int block[90][3], int size[3]){
	if(size[0] == size[2]){
		block[num][0] = size[0];
		block[num][1] = size[1];
		block[num++][2] =size[2];
	}
	else if(size[0] == size[1] || size[1] == size[2]){
		block[num][0] = size[0];
		block[num][1] = size[1];
		block[num++][2] =size[2];
		block[num][0] = size[1];
		block[num][1] = size[2];
		block[num++][2] =size[0];
	}
	else{
		block[num][0] = size[0];
		block[num][1] = size[1];
		block[num++][2] =size[2];
		block[num][0] = size[1];
		block[num][1] = size[2];
		block[num++][2] =size[0];
		block[num][0] = size[0];
		block[num][1] = size[2];
		block[num++][2] =size[1];
	}
}

void go(){
	for(int i = 0; i < num;i ++){
		for(int j = i + 1; j < num; j ++){
			if(block[i][0] > block[j][0] || (block[i][0] == block[j][0] && block[i][1] > block[j][1])){
				swap(block[i][0], block[j][0]);
				swap(block[i][1], block[j][1]);
				swap(block[i][2], block[j][2]);
			}
		}
	}

	for(int i = 0; i < num; i ++){
		for(int j = i + 1; j < num; j ++){
			if(block[i][0] < block[j][0] && block[i][1] < block[j][1]){
				if(height[i] + block[i][2] > height[j]) height[j] = height[i] + block[i][2];
			}
		}
	}

	for(int i = 0; i < num; i ++){
		if(maxh < height[i] + block[i][2]) maxh = height[i] + block[i][2];
	}
}

int main(){
	int kase = 1;
	while(1){
		cin >> n;
		if(n == 0) break;

		num = 0;
		int size[3];
		for(int i = 0; i < n; i ++){
			//cin >> size[0] >> size[1] >> size[2];
			scanf("%d %d %d",&size[0], &size[1], &size[2]);
			sort(size[0], size[1], size[2]);
			standardize(block, size);
		}
		memset(height, 0, sizeof(height));
		maxh = 0;
		go();
		//cout << "Case " << kase ++ << ": maximum height = "<< maxh << endl;
		printf("Case %d: maximum height = %d\n", kase ++, maxh);
	}
	return 0;
}
