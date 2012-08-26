/**
 * ZOJ 2321 Filling Out the Team
 *
 * 2005/05/04 By adai
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

double speed, weight, strength;

int Run() {
	int num = 0;
	if (speed <= 4.5 && weight >= 150 && strength >= 200) {
		++num;
		printf("Wide Receiver");
	}
	if (speed <= 6 && weight >= 300 && strength >= 500) {
		if (num++) printf(" ");
		printf("Lineman");
	}
	if (speed <= 5 && weight >= 200 && strength >= 300) {
		if (num++) printf(" ");
		printf("Quarterback");
	}
	if (!num) printf("No positions");
	printf("\n");
	return 0;
}

int main() {
	while (scanf("%lf %lf %lf", &speed, &weight, &strength)) {
		if (speed == 0 && weight == 0 && strength == 0) break;
		Run();
	}
	return 0;
}
