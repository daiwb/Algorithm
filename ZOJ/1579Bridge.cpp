/*
zju 1579 Bridge
00:00.46 1336k
2004.08.22 by adai
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

#ifndef WIN32
typedef long long i64;
#else
typedef __int64 i64;
#endif

void input(i64 &a)
{
	char temp[1000];
    cin >> temp;
    a = 0;
    for(int i = 0; temp[i] != '\0'; ++ i)
        a = a * 10 + (int)(temp[i] - '0');
}

void print(i64 a)
{
    if(a > 9) print(a/10);
    cout << (int)(a%10);
}

int cmp(const void *t1,const void *t2)
{
	i64 *a, *b; 
	a = (i64 *)t1;
	b = (i64 *)t2;
	return (*a) - (*b);
}

i64 p[100005];

int main() {
	int n;
	while(1) {
		cin >> n;
		if(cin.fail()) break;
		if(n == 0){
			cout << 0 << endl;
			continue;
		}

		for(int i = 0; i < n; i ++){
			input(p[i]);
		}
		qsort(p, n, sizeof(i64), cmp);
		i64 total = 0, end;
		end = n - 1;
		i64 a, b, z, y;
		while(1) {
			if(end == 0) {
				total += p[0];
				break;
			}
			if(end == 1) {
				total += p[1];
				break;
			}
			if(end == 2) {
				total += p[0] + p[1] + p[2];
				break;
			}
			a = p[0], b = p[1], z = p[end], y = p[end - 1];
			if (2 * b >= a + y) total += z + a + y + a;
			else total += a + b + b + z;
			end -= 2;
		}
		print(total);
		cout << endl;
	}
	return 0;
}