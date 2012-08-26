/**
Author: Rafail
ID: 003796
Problem: 186
Contest: 0
Date: 2003-12-17 22:38:36

Ivan...
Is seems to me, you misunderstood the specification. At first, I was sure it was totally incomprehensible, too. But my solution was accepted at last... So I hope the God lets the following explanation be helpful to you (or anybody else trying to solve this problem):

If you have 2 links 1 1, let us represent them as follows: O O.
It will take you 1 minute (according to the problem specification) to:
1. to unchain the left link : U O
2. to put into the unchained link the second link : UO
3. to chain the unchained link : OO

If you have 3 links 1 1 1 (O O O), it may take you 2 minutes to reach the aim:
MINUTE #1
1. you unchain link #1 : U O O
2. you put link #2 into it : UO O
3. you chain link #1 back : OO O
Now you have 2 links 2 1 (OO O). What are we going to do next?
MINUTE #2
1. you unchain link #2 : OU O
2. you put link #3 into it : OUO
3. you chain link #2 back : OOO

You can also save some time and do everything in a minute as follows:
1. you unchain link #2 : O U O
2. you put links #1 and #3 into it : OUO
3. you chain link #2 back : OOO

Good luck!
Best wishes,
	Raphail
*/	

//ac

#include <iostream>
using namespace std;

int a[100];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int ret = 0, s = 0, t = n - 1;
	while (s < t) {
		++ret;
		--a[s];
		a[t - 1] += a[t + 1];
		--t;
		if (a[s] == 0) ++s;
	}
	cout << ret << endl;
	return 0;
}

