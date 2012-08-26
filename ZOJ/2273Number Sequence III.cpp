/*
 * ZJU 2273 Number Sequence III
 * 00:00.26 436k
 * BY ADAI
 */

#include <iostream>
#include <cmath>
using namespace std;

int table[5] = {10, 100, 1000, 10000};

int getlen(int n){
	if(n <= 9) return n;
	else if(n <= 99) return 9 + (n - 9) * 2;
	else if(n <= 999) return 9 + 90 * 2 + (n - 99) * 3;
	else if(n <= 9999) return 9 + 90 * 2 + 900 * 3 +(n - 999) * 4;
	else if(n <= 99999) return 9 + 90 * 2 + 900 * 3 + 9000 * 4 + (n - 9999) * 5;
	return 0;
}

int solve(int i){
	if(i <= 9){
		return i;
	}
	else if(i <= 9 + 90 * 2){
		i -= 9;
		int s = i % 2;				//s表示要输出的数字在t中从左至右的位置(0表示在最右边)
		int t = (i + 1) / 2 + 9;	//t表示该数字(要加上基数,比如二位数中第一个是1+9=10),下同
		if(s == 0) return t % 10;
		else return t / 10;
	}
	else if(i <= 9 + 90 * 2 + 900 * 3){
		i -= 9 + 90 * 2;
		int s = i % 3;
		int t = (i + 2) / 3 + 99;
		if(s == 0) return t % 10;
		else return t / table[2 - s] % 10;
	}
	else if(i <= 9 + 90 * 2 + 900 * 3 + 9000 * 4){
		i -= 9 + 90 * 2 + 900 * 3;
		int s = i % 4;
		int t = (i + 3) / 4 + 999;
		if(s == 0) return t % 10;
		else return t / table[3 - s] % 10;
	}
	else if(i <= 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5){
		i -= 9 + 90 * 2 + 900 * 3 + 9000 * 4;
		int s = i % 5;
		int t = (i + 4) / 5 + 9999;
		if(s == 0) return t % 10;
		else return t / table[4 - s] % 10 ;
	}
}

int main(){
	int n;
	//FILE* in;
	//FILE* out;
	//in = fopen("input","r");
	//out = fopen("output","w");
	//while(fscanf(in, "%d\n", &n) != EOF){
	while(cin >> n){	
		int len = getlen(n);

		int a[2];
		a[0] = 1, a[1] = 2;
		int add = 1, sign = 0;
		
		while(1){
			add *= 2;

			if(sign){
				a[0] = a[1];
				a[1] = a[0] + add;
			}
			else{
				a[1] = a[0] + add;
			}
			sign = (sign + 1) % 2;
			
			if(a[1] > len) break;
		}

		int res = solve(a[0]);
		cout << res << endl;
		//fprintf(out, "%d\n", res);
	}
	//fclose(in);
	//fclose(out);
	return 0;
}
