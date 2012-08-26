#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

int n;

void Run() {
	set<int> mm;
  for (int i = 0; i < n; ++i) {
		int in;
		cin >> in;
		mm.insert(in);
  }
	set<int>::iterator pos;
	int flag = 1;
	for (pos = mm.begin(); pos != mm.end(); ++pos) {
		if (flag) flag = 0;
		else cout << ' ';
		cout << *pos;
	}
	cout << endl;
}

int main() {
  while (cin >> n && n) {
    Run();
  }
  return 0;
}
