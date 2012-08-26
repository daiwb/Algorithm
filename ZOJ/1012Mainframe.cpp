/*
zju 1012 Mainframe
00:03.61 1180k
2004.08.16 by adai
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#ifdef WIN32
#define for if(0);else for
#endif

class job {
public:
	int a, b, t, u, v, w, x;
}j[10000];

int cmp(const void *t1, const void *t2) {
	job *a, *b; 
	a = (job *)t1;
	b = (job *)t2;
	if ((*a).t < (*b).t || ((*a).t == (*b).t && (*a).v > (*b).v)) return -1;
	return 1;
} 

int main () {
	int f;
	int kase = 1;
	while (cin >> f && f != 0) {
		int m, n, l;
		cin >> m >> n >> l;

		for (int i = 0; i < l; i ++) {
			cin >> j[i].a >> j[i].b >> j[i].t >> j[i].u >> j[i].v >> j[i].w >> j[i].x;
		}
		qsort(j, l, sizeof(job), cmp);
		j[l].t = 10005;
		/*for (int i = 0; i < l; i ++) {
			cout << j[i].t << " " << j[i].v << endl;
		}*/
		
		int income = 0;
		int ii = 0;
		vector<job> jj;
		for (int i = 0; i < f; i ++) {
			while (i == j[ii].t) jj.push_back(j[ii ++]);
			int tm = m, tn = n;
			for (int s = 0; s < jj.size(); s ++) {
				if (tm >= jj[s].a && tn >= jj[s].b) {
					tm -= jj[s].a, tn -= jj[s].b;
					income += jj[s].v;
					if (i + 1 > jj[s].u) income -= (i + 1 - jj[s].u) * jj[s].x;
					else income += (jj[s].u - i - 1) * jj[s].w;
					jj.erase(jj.begin() + s, jj.begin() + s + 1);
					s --;
				}
			}
		}
		for (int i = 0; i < jj.size(); i ++) {
			if (jj[i].u <= f) income -= (f - jj[i].u) * jj[i].x;
		}
		cout << "Case " << kase ++<< ": " << income << endl << endl;
	}
	return 0;
}
