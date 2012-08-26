//zju 1298 Domino Effect

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int N;
double dis[500][500], cost[500][500];

int choose (double[][500], int, char[]);
void ShortestPath (double cost[][500], double distance[][500], int n, int start)
{
	int i, j, k;
	char bb[500];
	for (i = 0; i < n; i ++)
		bb[i] = 0, distance[i][i] = cost[0][i];
	bb[start] = 1; distance[start][start] = 0;
	for (i = 0; i < n - 2; i ++) {
		bb[j = choose (distance, n, bb)] = 1;
		for (k = 0; k < n; k ++)
			if (!bb[k])
			if (distance[j][j] + cost[j][k] < distance[k][k])
				distance[k][k] = distance[j][j] + cost[j][k];
	}
}

int choose (double distance[][500], int n, char bb[])
{
	int i, minpos;
	double min = 1e100;
	for (i = 0; i < n; i ++)
		if (distance[i][i] < min && !bb[i])
			min = distance[minpos = i][i];
	return minpos;
}

#define min(a, b) ((a) < (b) ? (a) : (b))

void Run ()
{
	int i, j, pos[2];
	double re = -1;
	ShortestPath(cost, dis, N, 0);
	for (i = 0; i < N; i ++) {
		if (re < dis[i][i])
			re = dis[pos[0] = i][pos[1] = i];
	}

	for (i = 0; i < N; i ++)
	for (j = i + 1; j < N; j ++) {
		if (cost[i][j] >= 2000000000) continue;
		dis[i][j] = min(dis[i][i], dis[j][j]) + cost[i][j];
		if (cost[i][j] > fabs(dis[i][i] - dis[j][j]))
			dis[i][j] -= (cost[i][j] - fabs(dis[i][i] - dis[j][j])) / 2;
		if (re < dis[i][j])
			re = dis[pos[0] = i][pos[1] = j];
	}

	cout << "The last domino falls after " << re << " seconds, ";
	if (pos[0] == pos[1])
		cout << "at key domino " << pos[0] + 1 << "." << endl;
	else cout << "between key dominoes " << pos[0] + 1 << " and " << pos[1] + 1 << "." << endl;
}

int main ()
{
	int Case = 1, a, b, l, M;
	cout.precision(1); cout.setf(ios::fixed);
	for (cin >> N >> M; N || M; cin >> N >> M) {
		for (int i = 0; i < N; i ++)
		for (int j = 0; j < N; j ++)
			cost[i][j] = 2000000000;
		for (int i = 0; i < M; i ++) {
			cin >> a >> b >> l;
			cost[a - 1][b - 1] = cost[b - 1][a - 1] = l;
		}
		cout << "System #" << Case ++ << endl;
		Run();
		cout << endl;
	}
	return 0;
}
