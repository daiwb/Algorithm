#include <iostream>
using namespace std;

void run() {
    int n;
    cin >> n;
    cout << max(n - 2, 0) << endl;
}

int main() {
    int kase;
    for (cin >> kase; kase; --kase) {
        run();
    }
    return 0;
}
