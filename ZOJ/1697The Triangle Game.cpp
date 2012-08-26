#include <iostream>
#include <string>
using namespace std;

int a[6][3];
int seq[100], res[100], maxn;

void search(int layer, char bb[])
{
	if (layer == 6) {
		if (seq[6] == seq[0]) {
			int re = 0;
			for (int i = 0; i < 6; i ++)
				re += res[i];
			maxn = maxn > re ? maxn : re;
		}
	}
	else {
		for (int i = 0; i < 6; i ++) {
			if (bb[i]) continue;
			bb[i] = 1;
			for (int j = 0; j < 3; j ++) {
				if (a[i][j] == seq[layer]) {
					res[layer] = a[i][(j + 2) % 3];
					seq[layer + 1] = a[i][(j + 1) % 3];
					search(layer + 1, bb);
				}
			}
			bb[i] = 0;
		}
	}
}

void Run()
{
	char bb[6];
	memset(bb, 0, sizeof(bb));
	bb[0] = 1; maxn = 0;
	for (int i = 0; i < 3; i ++) {
		res[0] = a[0][i]; seq[0] = a[0][(i + 1) % 3]; seq[1] = a[0][(i + 2) % 3];
		search(1, bb);
	}
	if (!maxn) cout << "none" << endl;
	else cout << maxn << endl;
}

int main()
{
	string temp;
	do {
		for (int i = 0; i < 6; i ++)
		for (int j = 0; j < 3; j ++)
			cin >> a[i][j];
		Run();
		cin >> temp;
	}while(temp != "$");
	return 0;
}
