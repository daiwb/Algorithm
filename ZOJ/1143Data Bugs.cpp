#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b)
{
	return a % b ? gcd(b, a % b) : b;
}

long lcm(long a, long b)
{
	return a / gcd(a,b) * b;
}

class computer {
public:
    int y, a, b, d;
};

int n;

void Run() {
    vector<computer> com;
    for (int i = 0; i < n; ++i) {
        computer tmp;
        cin >> tmp.y >> tmp.a >> tmp.b;
        tmp.d = tmp.b - tmp.a;
        com.push_back(tmp);
    }
    int year = com[0].y, interval = com[0].d;
    for (int i = 1; i < n; ++i) {
        while (year < com[i].y) year += interval;
        while (year % com[i].d != com[i].y % com[i].d && year < 10000) year += interval;
		if (year >= 10000) {
			cout << "Unknown bugs detected." << endl;
			return;
		}
		interval = lcm(interval, com[i].d);
    }
    cout << "The actual year is " << year << "." << endl;
}

int main() {
    int kase = 0;
    while (cin >> n && n) {
        cout << "Case #" << ++kase << ":" << endl;
        Run();
        cout << endl;
    }
    return 0;
}
