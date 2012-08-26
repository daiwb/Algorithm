#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

void Run() {
    int n, ret = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] * (n - i) > ret) ret = a[i] * (n - i);
    }
    cout << ret << endl;
}

int main() {
    int kase;
    for (cin >> kase; kase; --kase) {
        Run();
    }
    return 0;
}