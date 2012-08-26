//ac

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

#define MAXN 400000
#define sig(x) ((x)>0?1:-1)
#define abs(x) ((x)>0?(x):-(x))
#define _ufind_run(x) for(;p[t=abs(x)];x=sig(x)*p[abs(x)],p[t]=sig(p[t])*(p[abs(x)]?p[abs(x)]:abs(p[t])))
#define _run_both _ufind_run(i);_ufind_run(j)
#define _set_side(x) p[abs(i)]=sig(i)*(abs(i)==abs(j)?0:(x)*j)
#define _judge_side(x) (i==(x)*j&&i)

struct ufind{
	int p[MAXN],t;
	void init(){memset(p,0,sizeof(p));}
	int set_friend(int i,int j){_run_both;_set_side(1);return !_judge_side(-1);}
	int set_enemy(int i,int j){_run_both;_set_side(-1);return !_judge_side(1);}
	int is_friend(int i,int j){_run_both;return _judge_side(1);}
	int is_enemy(int i,int j){_run_both;return _judge_side(-1);}
};

class point {
	public:
		int x, y;
		bool operator < (const point& c) const {
			if (x != c.x) return x < c.x;
			else return y < c.y;
		}
};

int m;

int main() {
	scanf("%d", &m);
	int ret = 0;
	ufind uf;
	uf.init();
	map<point, int> mm;
	map<point, int>::iterator it;
	int num = 0;
	for (int i = 0; i < m; ++i) {
		point a, b;
		scanf("%d %d %d %d", &a.x, &a.y, &b.x, &b.y);
		if (ret) continue;
		it = mm.find(a);
		if (it == mm.end()) mm[a] = num++;
		it = mm.find(b);
		if (it == mm.end()) mm[b] = num++;
		int na = mm[a], nb = mm[b];
		if (uf.is_friend(na, nb)) ret = i + 1;
		uf.set_friend(na, nb);
	}
	printf("%d\n", ret);
	return 0;
}

