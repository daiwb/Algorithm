/*
zju 2122 A Flea on a Chessboard
00:00.01 436k
2004.08.05 by adai
*/


#include <iostream>
using namespace std;

int main(){
	int s, x, y, dx, dy;
	while(1){
		cin >> s >> x >> y >> dx >> dy;
		if(s == 0 && x == 0 && y == 0 && dx == 0 && dy == 0) break;

		int tx = x % s;
		int ty = y % s;

		int step = 0;
		int color;

		if((x / s + y / s) % 2 == 0) color = 1;
		else color = 0;

		int count = 0;

		while(1){
			if(color == 0 && x % s != 0 && y % s != 0) break;
			x += dx, y += dy;
			step ++;
			if((x / s + y / s) % 2 == 0){
				color = 1;
				if(x % s == tx && y % s == ty){
					if(count) break;
					count ++;
				}
			}
			else color = 0;
		}
		if(color == 0)
			cout << "After " << step << " jumps the flea lands at (" << x << ", " << y << ")." << endl;
		else cout << "The flea cannot escape from black squares." << endl;
	}
	return 0;
}
