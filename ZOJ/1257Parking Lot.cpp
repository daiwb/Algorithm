/*
 * ZJU 1257 Parking Lot
 * 00:00.00 844k
 * 2005.02.01 by adai
 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define debug 1

class car {
public:
	int InitPos;
	int CurPos;
	int flag;
	car(int a) {
		InitPos = CurPos = a;
		flag = 0;
	}
};

int v[20];

int main() {
	vector<car> mm;
	int in, n = 0, done = 0;
	memset(v, -1, sizeof(v));

	while (1) {
		cin >> in;
		if (in == 99) break;
		in--;
		mm.push_back(car(in));
		v[in] = n;
		n++;
	}

	while (cin >> in) {
		if (debug && in == 99) break;
		if (done) continue;
		in--;
		int ii = in;
		while (v[ii] == -1) {
			ii = (ii + 19) % 20;
			if (ii == in) {
				done = 1;
				break;
			}
		}
		if (done) continue;
		int dis = (in - ii + 20) % 20;
		mm[v[ii]].CurPos = in;
		mm[v[ii]].flag = 1;
		for(int i = 0; i < n; i++) {
			if (mm[i].flag) continue;
			mm[i].CurPos = (mm[i].CurPos + dis) % 20;
		}
		memset(v, -1, sizeof(v));
		for(int i = 0; i < n; i++) {
			if (mm[i].flag) continue;
			v[mm[i].CurPos] = i;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if (mm[i].flag) cout << "Original position " << mm[i].InitPos + 1 << " parked in " << mm[i].CurPos + 1 << endl;
		else cout << "Original position " << mm[i].InitPos + 1 << " did not park" << endl;
	}
	return 0;
}
