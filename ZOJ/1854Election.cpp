#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int main () {
	int n, m;
	char name[20][85], party[20][85];
	int count[20];
	while (1) {
		cin >> n;
		if (cin.fail()) break;
		cin.getline(name[0], 85, '\n');
		for (int i = 0; i < n; i ++) {
			cin.getline(name[i], 85, '\n');
			cin.getline(party[i], 85, '\n');
			count[i] = 0;
		}
		cin >> m;
		char vote[85];
		cin.getline(vote, 85, '\n');
		while (m --) {
			cin.getline(vote, 85, '\n');
			for (int j = 0; j < n; j ++) {
				if (strcmp(name[j], vote) == 0) {
					count[j] ++;
					break;
				}
			}			
		}


		/*
		int index, num = 0;
		for (int i = 0; i < n; i ++) {
			if (count[i]) {
				index = i;
				num = 1;
				break;
			}
		}
		if (num == 0) {
			cout << "tie" << endl;
			continue;
		}
		for (int i = index + 1; i < n; i ++) {
			if (count[i] > count[index]) {
				index = i, num = 1;
			}
			if (count[i] == count[index]) num ++;
		}
		if (num > 1) cout << "tie" << endl;
		else cout << party[index] << endl;
		*/


		int index = 0, tie = 0;
		for (int i = 1; i < n; i ++) {
			if (count[i] > count[index]) {
				index = i, tie = 0;
			}
			else if (count[i] == count[index]) tie = 1;
		}
		if (tie) cout << "tie" << endl;
		else cout << party[index] << endl;
	}
	return 0;
}
