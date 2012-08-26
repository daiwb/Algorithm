#include <iostream>
#include <map>
#include <utility>
using namespace std;

long long N;
map <pair<long long, int>, int> res;

int search(long long start, int turn)
{
	pair<long long, int> temp(start, turn);
	if (res.find(temp) != res.end())
		return res[temp];
	if (start * 9 >= N) return res[temp] = turn;
	for (int n = 2; n < 10; n ++) {
		if (search(start * n, 3 - turn) == turn) {
			return res[temp] = turn;
		}
	}
	return res[temp] = 3 - turn;
}

int main()
{
	while (cin >> N) {
		res.clear();
		cout << (search(1, 1) == 1 ? "Stan wins." : "Ollie wins.") << endl;
	}
	return 0;
}

