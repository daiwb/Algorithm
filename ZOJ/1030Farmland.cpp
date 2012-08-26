/*
 * zju 1030 Farmland
 * 00:00.01 488k
 * 2004.09.24 by adai
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class point {
public:
	int x;
	int y;
	int num;
	point(int xx, int yy, int number) {
		x = xx, y = yy, num = number;
	}
};

//计算cross product (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//计算三角形面积,输入三顶点
double area_triangle(point p1,point p2,point p3){
	return fabs(xmult(p1,p2,p3))/2;
}

//计算多边形面积,顶点按顺时针或逆时针给出
double area_polygon(int n,vector <point> p){
	double s1=0,s2=0;
	int i;
	for (i=0;i<n;i++)
		s1+=p[(i+1)%n].y*p[i].x,s2+=p[(i+1)%n].y*p[(i+2)%n].x;
	return fabs(s1-s2)/2;
}

#define EPS 1e-8
#define MAXN 200
bool mat[MAXN][MAXN];
bool visited[MAXN];

int n, size, res;

int dfs(int ii, int step, vector <point>& mm, vector <point>& v) {
	if (step == size) {
		//for (int i = 0; i < size; i ++) printf("%d %d %d\n", mm[i].x, mm[i].y, mm[i].num);
		//cout << "********************" << endl;
		if (mat[ii][mm[0].num]) {
			for (int i = 0; i < size; i ++) {
				for (int j = i + 2; j < size; j ++) {
					if ((j + 1) % size == i) continue;
					if (mat[mm[i].num][mm[j].num]) return 0;
				}
			}
			double area = area_polygon(size, mm);

			for (int i = 0; i < n; i ++) {
				if (visited[i]) continue;
				double test_area = 0;
				for (int j = 0; j < size; j ++) {
					test_area += area_triangle(mm[j], mm[(j + 1) % size], v[i]);
				}
				if (fabs(area - test_area) < EPS) return 0;
			}
			res ++;
		}
		return 0;
	}

	for (int i = 0; i < n; i ++) {
		if (visited[i]) continue;
		if (!mat[ii][v[i].num]) continue;
		visited[i] = 1;
		mm.push_back(v[i]);
		dfs(i, step + 1, mm, v);
		mm.pop_back();
		visited[i] = 0;
	}

	return 0;
}

int main() {
	int kase;
	scanf("%d", &kase);
	while (kase --) {
		memset(mat, 0, sizeof(mat));
		vector <point> v;
		v.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			int num, x, y;
			scanf("%d %d %d", &num, &x, &y);
			v.push_back(point(x, y, num - 1));
			int d;
			scanf("%d", &d);
			for (int j = 0; j < d; j ++) {
				int nn;
				scanf("%d", &nn);
				mat[num - 1][nn - 1] = mat[nn - 1][num - 1] = 1;
			}
		}
		scanf("%d", &size);
		if (size <= 2) {
			printf("0\n");
			continue;
		}
		res = 0;
		memset(visited, 0, sizeof(visited));
		vector <point> mm;
		for (int i = 0; i < n; i ++) {
			mm.clear();
			visited[i] = 1;
			mm.push_back(v[i]);
			dfs(i, 1, mm, v);
			mm.pop_back();
			visited[i] = 0;
		}
		//printf("res = %d\n", res);
		res /= size * 2;
		printf("%d\n", res);
	}
	return 0;
}
