#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define for if(0);else for

int N;
string word[130000];

int main()
{
	int N = 0;
	string str;
	while (cin >> str)
		word[N ++] = str;
	for (int i = 1; i < N; i ++) {
		for (int j = 1; j < word[i].size(); j ++) {
			if (binary_search(word, word + N, word[i].substr(0, j)))
			if (binary_search(word, word + N, word[i].substr(j))) {
				cout << word[i] << endl;
				break;
			}
		}
	}
	return 0;
}

