/**
 * ZOJ 2416 Open the Lock
 */

#include <iostream>
#include <string>
using namespace std;

class number {
public:
	int num[4];
}mm[10000];

int a[4], b[4];
int init, pwd, ret;
int visited[10000];

int bfs()
{
	int head, tail, nhead, ntail;
	head = tail = 0;
	ret = 0;
	while (1) {
		if (visited[pwd]) return 0;
		++ret;
		nhead = tail + 1, ntail = tail;
		for (int i = head; i <= tail; ++i) {
			int tmp[4], temp[4], sum;
			memcpy(tmp, mm[i].num, sizeof(tmp));
			for (int j = 0; j < 4; ++j) {
				memcpy(temp, tmp, sizeof(tmp));
				if (++temp[j] == 10) temp[j] = 1;
				sum = 0;
				for (int k = 0; k < 4; ++k) sum = sum * 10 + temp[k];
				if (visited[sum] == 0) {
					visited[sum] = 1;
					++ntail;
					memcpy(mm[ntail].num, temp, sizeof(temp));
				}
				memcpy(temp, tmp, sizeof(tmp));
				if (--temp[j] == 0) temp[j] = 9;
				sum = 0;
				for (int k = 0; k < 4; ++k) sum = sum * 10 + temp[k];
				if (visited[sum] == 0) {
					visited[sum] = 1;
					++ntail;
					memcpy(mm[ntail].num, temp, sizeof(temp));
				}
			}
			for (int j = 0; j < 3; ++j) {
				memcpy(temp, tmp, sizeof(tmp));
				temp[j] = tmp[j + 1], temp[j + 1] = tmp[j];
				sum = 0;
				for (int k = 0; k < 4; ++k) sum = sum * 10 + temp[k];
				if (visited[sum] == 0) {
					visited[sum] = 1;
					++ntail;
					memcpy(mm[ntail].num, temp, sizeof(temp));
				}
			}
		}
		if (ntail < nhead) break;
		for (int i = nhead; i <= ntail; ++i) {
			memcpy(mm[i - nhead].num, mm[i].num, sizeof(mm[i].num));
		}
		head = 0, tail = ntail - nhead;
	}
	return 0;
}

int Run()
{
	char input[5];
	cin >> input;
	for (int i = 0; i < 4; ++i) a[i] = input[i] - '0';
	cin >> input;
	for (int i = 0; i < 4; ++i) b[i] = input[i] - '0';
	memset(visited, 0, sizeof(visited));
	init = pwd = 0;
	for (int i = 0; i < 4; ++i) {
		init = init * 10 + a[i];
		pwd  = pwd  * 10 + b[i];
	}
	visited[init] = 1;
	memcpy(mm[0].num, a, sizeof(a));
	bfs();
	cout << ret << endl;
	return 0;
}

int main() {
	int kase;
	for (cin >> kase; kase; kase--) {
		Run();
	}
	return 0;
}
