#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long N;
long ca[20];
typedef struct no{
	struct no *left, *right;
}NODE;
NODE buffer[20];
int top;

NODE *alloc()
{
	buffer[top].left = buffer[top].right = NULL;
	return &buffer[top++];
}

void Search(NODE *node, long n, long k)
{
	if (n > 1) {
		long sn, i;
		for (sn = i = 0; i < n; i ++) {
			if (sn + ca[i] * ca[n - 1 - i] * k >= N) break;
				sn += ca[i] * ca[n - 1 - i] * k;
		}
		N -= sn;
		if (i) {
			node->left = alloc();
			Search (node->left, i, ca[n - 1 - i] * k);
		}
		if (n - 1 - i) {
			node->right = alloc();
			Search (node->right, n - 1 - i, k);
		}
	}
}

void Print(NODE *node)
{
	if (node->left) {
		cout << "(";
		Print (node->left);
		cout << ")";
	}
	cout << "X";
	if (node->right) {
		cout << "(";
		Print (node->right);
		cout << ")";
	}
}

void Run()
{
	long n, sn = 0, i;
	for (n = 1; n < 18; sn += ca[n++])
		if (sn + ca[n] >= N) break;
	top = 0;
	NODE *head = alloc(), *node = head;
	N -= sn;
	for (sn = i = 0; i < n; i ++) {
		if (sn + ca[i] * ca[n - 1 - i] >= N) break;
		sn += ca[i] * ca[n - 1 - i];
	}
	N -= sn;
	if (N) {
		if (i) {
			node->left = alloc();
			Search (node->left, i, ca[n - 1 - i]);
		}
		if (n - 1 - i) {
			node->right = alloc();
			Search (node->right, n - 1 - i, 1);
		}
	}
	Print(head);
	cout << endl;
}

void Init()
{
	ca[0] = ca[1] = 1;
	for (long n = 1; n <= 16; n ++)
		ca[n + 1] = ca[n] * (4 * n + 2) / (n + 2);
	ca[17] = 129644790;
}

int main()
{
	Init();
	for (cin >> N; N; cin >> N)
		Run ();
	return 0;
}
