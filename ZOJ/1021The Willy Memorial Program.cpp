//zju 1021 The Willy Memorial Program

//#pragma warning(disable:4786)
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

/*
#ifdef WIN32
#define for if(0);else for
#define cin in
fstream in("1021.txt", ios::in);
#endif
*/

int n, m, dest, height;
int pipe[30][3], link[60][3];

void Run()
{
	vector<int> aa[30][30];
	int t;
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) {
			if (link[i][1] >= pipe[j][1] && link[i][1] <= pipe[j][1] + pipe[j][2] && (link[i][0] == pipe[j][0] || link[i][0] == pipe[j][0] + 1)) {
				for (int k = 0; k < n; k ++) {
					if (link[i][1] >= pipe[k][1] && link[i][1] <= pipe[k][1] + pipe[k][2] && (link[i][0] + link[i][2] == pipe[k][0] || link[i][0] + link[i][2] == pipe[k][0] + 1)) {
						aa[j][k].push_back(link[i][1]);
						aa[k][j].push_back(link[i][1]);
					}
				}
			}
		}
	}

	int hh[30];
	for (int i = 0; i < n; i ++)
		hh[i] = pipe[i][1] + pipe[i][2];
	set <int> xx, yy;
	xx.insert(0);
	for (t = 0; ; ) {
		for (bool fl = true; fl; xx = yy) {
			fl = false;
			yy = xx;
			for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++) {
				int ref = *it;
				for (int i = 0; i < n; i ++) {
					if (xx.find(i) != xx.end()) continue;
					for (int j = 0; j < aa[ref][i].size(); j ++) {
						if (hh[ref] <= aa[ref][i][j]) {
							fl = true;
							yy.insert(i);
						}
					}
				}
			}
		}

		if (xx.find(dest) != xx.end() && hh[dest] == height) break;
		int h = hh[0];
		bool en = false;
		for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++)
			h = hh[*it] > h ? hh[*it] : h;
		for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++) {
			if (hh[*it] == h && hh[*it] == pipe[*it][1])
				en = true;
		}
		if (en) break;
		for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++) {
			if (hh[*it] == h) hh[*it] --, t ++;
		}
		if (xx.find(dest) != xx.end() && hh[dest] == height) break;
	}
	if (hh[dest] == height) {
		for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++) {
			while (hh[*it] > height && hh[*it] > pipe[*it][1]) {
				hh[*it] --; t ++;
			}
		}
		for (set<int>::iterator it = xx.begin(); it != xx.end(); it ++) {
			if (hh[*it] <= pipe[*it][1]) {
				cout << "No Solution" << endl;
				return;
			}
		}
		cout << t << endl;
		return;
	}
	cout << "No Solution" << endl;
}

int main()
{
	int t;
	for (cin >> t; t; t --) {
		cin >> n;
		for (int i = 0; i < n; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> pipe[i][j];
		cin >> m;
		for (int i = 0; i < m; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> link[i][j];
		cin >> dest >> height;
		dest --;
		Run();
	}
	return 0;
}
