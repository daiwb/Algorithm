/*
zju 1076 Gene Assembly
00:00.00 448k
2004.08.17 by adai
*/

#include <iostream>
#include <string>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class exon {
public:
	int start;
	int end;
	int index;
}a[1000];

int cmp(const void *t1, const void *t2) {
	exon *a, *b; 
	a = (exon *)t1;
	b = (exon *)t2;
	return (*a).end - (*b).end;
}

int main () {
	int n;
	while (cin >> n && n != 0) {
		for (int i = 0; i < n; i ++) {
			cin >> a[i].start >> a[i].end;
			a[i].index = i + 1;
		}
		qsort(a, n, sizeof(exon), cmp);
		int first = 1;
		int bound = 0;
		int tt = 0;
		while (1) {
			for (; tt < n; tt ++) {
				if (a[tt].start > bound) {
					if (!first) cout << " ";
					else first = 0;
					cout << a[tt].index;
					bound = a[tt].end;
					break;
				}
			}
			if (tt == n) {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}