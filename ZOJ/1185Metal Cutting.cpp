//zju 1185 Metal Cutting


#include <iostream.h>
#include <math.h>
#include <string.h>

#define eps 1e-10
#define min(a, b) ((a) < (b) ? (a) : (b))

int N;
double w, h, po[10][2], angle[10][2], dis[10], dis2[10][2];
double min;

void Perm(int list[], int i)
{
	int j, temp;
	if (i == N - 1) {
		// add code here
		double re = 0, tt, t1, t2, t0;
		char aa = 0;
		for (i = 0; i < N; i ++) {
			re += dis[list[i]];
			if (fabs(angle[list[i]][1]) > eps)
				t0 = (po[(list[i] + 1) % N][1] - po[list[i]][1]) / angle[list[i]][1];
			else t0 = (po[(list[i] + 1) % N][0] - po[list[i]][0]) / angle[list[i]][0];
			t1 = 1e100, t2 = -1e100;
			for (j = aa = 0; j < i; j ++) {
				if (fabs(tt = angle[list[i]][0] * angle[list[j]][1] - angle[list[j]][0] * angle[list[i]][1]) > eps) {
					tt = (angle[list[j]][0] * (po[list[i]][1] - po[list[j]][1]) + angle[list[j]][1] * (po[list[j]][0] - po[list[i]][0])) / tt;
					if (tt > eps)
						t1 = (tt > t1 ? t1 : tt);
					else if (tt < -eps)
						t2 = (tt > t2 ? tt : t2);
					else aa = 1;
				}
			}
			if (aa) {
				if (t0 > eps) t2 = 0;
				else t1 = 0;
			}
			if (t0 > eps)
				tt = min(dis2[list[i]][0], -t2), t0 = min(dis2[list[i]][1], t1 - dis[list[i]]);
			else tt = min(dis2[list[i]][0], t1), t0 = min(dis2[list[i]][1], -t2 - dis[list[i]]);
			re += tt + t0;
		}
		min = (re < min ? re : min);
	}
	else {
		temp = list[i];
		for (j = i; j < N; j ++) {
			list[i] = list[j]; list[j] = temp;
			Perm(list, i + 1);
			list[j] = list[i];
		}
		list[i] = temp;
	}
}

void Run ()
{
	int list[10];
	for (int i = 0; i < N; i ++) {
		list[i] = i;
		dis[i] = sqrt((po[i][0] - po[(i + 1) % N][0]) * (po[i][0] - po[(i + 1) % N][0]) + (po[i][1] - po[(i + 1) % N][1]) * (po[i][1] - po[(i + 1) % N][1]));
		angle[i][0] = (po[i][0] - po[(i + 1) % N][0]) / dis[i];
		angle[i][1] = (po[i][1] - po[(i + 1) % N][1]) / dis[i];
		double t0;
		if (fabs(angle[i][1]) > eps)
			t0 = (po[(i + 1) % N][1] - po[i][1]) / angle[i][1];
		else t0 = (po[(i + 1) % N][0] - po[i][0]) / angle[i][0];
		double t1 = 1e100, t2 = -1e100, tt;
		if (fabs(angle[i][0]) > eps) {
			if ((tt = -po[i][0] / angle[i][0]) > eps)
				t1 = (tt > t1 ? t1 : tt);
			else t2 = (tt > t2 ? tt : t2);
			if ((tt = (w - po[i][0]) / angle[i][0]) > eps)
				t1 = (tt > t1 ? t1 : tt);
			else t2 = (tt > t2 ? tt : t2);
		}
		if (fabs(angle[i][1]) > eps) {
			if ((tt = -po[i][1] / angle[i][1]) > eps)
				t1 = (tt > t1 ? t1 : tt);
			else t2 = (tt > t2 ? tt : t2);
			if ((tt = (h - po[i][1]) / angle[i][1]) > eps)
				t1 = (tt > t1 ? t1 : tt);
			else t2 = (tt > t2 ? tt : t2);
		}
		if (t0 > eps)
			dis2[i][0] = -t2, dis2[i][1] = t1 - dis[i];
		else dis2[i][0] = t1, dis2[i][1] = -t2 - dis[i];
	}
	min = 1e100;
	Perm(list, 0);
	cout.precision(3); cout.setf(ios::fixed);
	cout << min << endl;
}

int main ()
{
	int t, aa = 1;
	cin >> t;
	while (t --) {
		cin >> w >> h >> N;
		for (int i = 0; i < N; i ++)
			cin >> po[i][0] >> po[i][1];
		if (aa) aa = 0; else cout << endl;
		cout << "Minimum total length = ";
		Run();
	}
	return 0;
}