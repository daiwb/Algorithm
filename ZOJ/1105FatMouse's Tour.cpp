#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

void Run() {
    double ret = 0;
    double x1, y1, x2, y2;
    char in[100];
    while (cin >> in && strcmp(in, "java") != 0) {
        x1 = atof(in);
        cin >> y1 >> x2 >> y2;
        ret += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    ret *= 3.0 / 500;
    int mm = ceil(ret);
    cout << mm / 60 << ':';
    if (mm % 60 < 10) cout << 0;
    cout << mm % 60 << endl;
}

int main() {
    int x, y;
    while (1) {
        cin >> x >> y;
        if (cin.fail()) break;
        Run();
    }
    return 0;
}
