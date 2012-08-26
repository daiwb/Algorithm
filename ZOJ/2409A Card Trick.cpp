/**
 * ZOJ 2409 A Card Trick
 *
 * 2005/05/07 By adai
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class card {
public:
	char value;
	char suit;
	int num;
}cc[5];

int ii[5];

void Run() {
	for (int i = 0; i < 5; ++i) {
		char input[3];
		scanf("%s", input);
		if (strlen(input) == 2) {
			cc[i].value = input[0], cc[i].suit = input[1];
			if (input[0] == 'A') cc[i].num = 1;
			else if (input[0] >= '2' && input[0] <= '9') cc[i].num = input[0] - '0';
			else if (input[0] == 'J') cc[i].num = 11;
			else if (input[0] == 'Q') cc[i].num = 12;
			else cc[i].num = 13;
		}
		else {
			cc[i].value = 'T', cc[i].suit = input[2];
			cc[i].num = 10;
		}
		cc[i].num *= 100;
		char ch = input[strlen(input) - 1];
		if (ch == 'C') cc[i].num += 1;
		else if (ch == 'D') cc[i].num += 2;
		else if (ch == 'H') cc[i].num += 3;
		else cc[i].num += 4;
	}
	for (ii[0] = 0; ii[0] < 5; ++ii[0]) {
		for (ii[1] = 0; ii[1] < 5; ++ii[1]) {
			if (ii[1] == ii[0]) continue;
			if (cc[ii[0]].suit != cc[ii[1]].suit) continue;
			for (ii[2] = 0; ii[2] < 5; ++ii[2]) {
				if (ii[2] == ii[0] || ii[2] == ii[1]) continue;
				for (ii[3] = 0; ii[3] < 5; ++ii[3]) {
					if (ii[3] == ii[0] || ii[3] == ii[1] || ii[3] == ii[2]) continue;
					ii[4] = 10 - ii[0] - ii[1] - ii[2] - ii[3];
					int index = 1, mm = cc[ii[2]].num;
					if (cc[ii[3]].num < mm) {
						index = 2;
						mm = cc[ii[3]].num;
					}
					if (cc[ii[4]].num < mm) {
						index = 3;
						mm = cc[ii[4]].num;
					}
					if (index == 1) {
						if (cc[ii[3]].num > cc[ii[4]].num) index += 3;
					}
					else if (index == 2) {
						if (cc[ii[2]].num > cc[ii[4]].num) index += 3;
					}
					else {
						if (cc[ii[2]].num > cc[ii[3]].num) index += 3;
					}
					index += cc[ii[1]].num / 100;
					if (index > 13) index -= 13;
					if (cc[ii[0]].num / 100 == index) {
						for (int d = 0; d < 5; ++d) {
							if (cc[ii[d]].value == 'T') printf(" 10");
							else printf(" %c", cc[ii[d]].value);
							printf("%c", cc[ii[d]].suit);
						}
						printf("\n");
						return;
					}
				}
			}
		}
	}
}

int main() {
	int kase;
	scanf("%d", &kase);
	for (int kk = 1; kk <= kase; ++kk) {
		printf("Problem %d:", kk);
		Run();
	}
	return 0;
}
