#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

class point {
public:
    double x;
    double y;
    point & operator = (const point &cc) {
        x = cc.x, y = cc.y;
    }
};

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point gop, dog, hole, ret;

int main() {
    string in;
    while(getline(cin, in)) {
		istringstream is(in);
		is >> gop.x >> gop.y >> dog.x >> dog.y;
		int flag = 0;
		double mm = -1;
		while (getline(cin, in) && in != "") {
			istringstream is(in);
			is >> hole.x >> hole.y;
			if (dis(gop, hole) * 2 < dis(dog, hole)) {
			    flag = 1;
			    if (mm < 0 || mm > dis(gop, hole)) {
			        mm = dis(gop, hole);
			        ret = hole;
			    }
			}
		}
		if (!flag) printf("The gopher cannot escape.\n");
		else printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", ret.x, ret.y);
	}
    return 0;
}
