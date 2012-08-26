#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define for if(0);else for

int N;
string na[30];
map <string, int> nameref;
int value[30], ref[30];

bool cmp(int a, int b)
{
	return value[a] < value[b];
}

void Run()
{
	for (int i = 0; i < N; i ++) ref[i] = i;
	sort(ref, ref + N, cmp);
	for (int i = 0; i < N - 1; i ++) {
		if (value[ref[N - 1]] == 0) break;
		cout << na[ref[N - 1]] << " " << na[ref[0]] << " " << value[ref[N - 1]] << endl;
		value[ref[0]] += value[ref[N - 1]];
		value[ref[N - 1]] = 0;
		sort(ref, ref + N, cmp);
	}
}

int main()
{
	int t, Case = 1, a, b, c;
	string aa, bb;
	for (cin >> N >> t; N || t; cin >> N >> t) {
		cout << "Case #" << Case ++ << endl;
		memset(value, 0, sizeof(value));
		for (int i = 0; i < N; i ++)
			cin >> na[i], nameref[na[i]] = i;
		for (int i = 0; i < t; i ++) {
			cin >> aa >> bb >> c;
			value[nameref[aa]] -= c;
			value[nameref[bb]] += c;
		}
		Run();
		cout << endl;
	}
	return 0;
}
