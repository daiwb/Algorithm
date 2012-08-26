//zju 2108 Elevator

#include <iostream>
using namespace std;

int main(){
	int n, time;
	while(1){
		cin >> n;
		if(n == 0) break;
		time = 5 * n;
		int dir = 0, next, from, to;
		for(int t = 0; t < n; t ++){
			cin >> next;
			if(dir == 0){
				dir = 1;
				from = 0;
				to = next;
			}
			else if(dir == 1){
				if(next > to) to = next;
				else{
					time += (to - from) * 6;
					from = to;
					to = next;
					dir = -1;
				}
			}
			else{
				if(next < to) to = next;
				else{
					time += (from - to) * 4;
					from = to;
					to = next;
					dir = 1;
				}
			}
		}
		if(dir == 1) time += (to - from) * 6;
		else time += (from - to) * 4;
		cout << time << endl;
	}
	return 0;
}
