#include <iostream>
using namespace std;

int width;

void Run() {
    int w, h, a, b, ca, cb;
    w = h = ca = cb = 0;
    while (cin >> a >> b) {
        if (a == -1 && b == -1) {
            if (ca > w) w = ca;
            h += cb;
            break;
        }
        if (ca + a > width) {
            if (ca > w) w = ca;
            h += cb;
            ca = a, cb = b;
        } else {
            ca += a;
            if (b > cb) cb = b;
        }
    }
    cout << w << " x " << h << endl;
}

int main() {
    while (cin >> width && width) {
        Run();
    }
    return 0;
}
