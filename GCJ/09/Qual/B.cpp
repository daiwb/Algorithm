#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

#define MAXH 100
#define MAXW 100

int T, H, W;
int mat[MAXH + 5][MAXW + 5];
int mm[MAXH + 5][MAXW + 5];

int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
char dd[27];

void run() {
	cin >> H >> W;
	REP(i,H) {
		REP(j,W) {
			cin >> mat[i][j];
		}
	}
	REP(i,27) dd[i] = '*';

	memset(mm, -1, sizeof(mm));
	int num = 1;
	REP(i,H) {
		REP(j,W) {
			if (mm[i][j] != -1) continue;
			vector<pair<int, int> > q;
			q.push_back(make_pair(i, j));
			int ci = i, cj = j;
			while (true) {
				int idx = -1, low;
				REP(d,4) {
					int ti = ci + dir[d][0], tj = cj + dir[d][1];
					if (ti < 0 || ti >= H || tj < 0 || tj >= W) continue;
					if (mat[ti][tj] >= mat[ci][cj]) continue;
					if (idx == -1) {
						idx = d;
						low = mat[ti][tj];
					} else if (mat[ti][tj] < low) {
						idx = d;
						low = mat[ti][tj];
					}
				}
				if (idx == -1) {
					REP(qi,q.size()) {
						mm[q[qi].first][q[qi].second] = num;
					}
					++num;
					break;
				}
				int ni = ci + dir[idx][0], nj = cj + dir[idx][1];
				if (mm[ni][nj] == -1) {
					q.push_back(make_pair(ni, nj));
					ci = ni, cj = nj;
				} else {
					REP(qi,q.size()) {
						mm[q[qi].first][q[qi].second] = mm[ni][nj];
					}
					break;
				}
			}
		}
	}

	char ch = 'a';
	REP(i,H) {
		REP(j,W) {
			int n = mm[i][j];
			if (dd[n] == '*') {
				dd[n] = ch;
				++ch;
			}
		}
	}
	REP(i,H) {
		REP(j,W) {
			if (j) cout << " ";
			cout << dd[mm[i][j]];
		}
		cout << endl;
	}
}

int main() {
	cin >> T;
	REP(t,T) {
		cout << "Case #" << t + 1 << ":" << endl;
		run();
	}
	return 0;
}
