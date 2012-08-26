/*
 * ZJU 1694 Shredding Company
 * 00:00.02 844k
 * 2005.03.02 by adai
 */

#include <iostream>
#include <cstring>
using namespace std;

int tar, num[6], len, tmp, ret, out[6], size, no, out2[6], size2;
char sor[10];

int search(int value, int ii)
{
	if (ii == len) {
		if (value == ret) {
			++no;
		}
		else if (value > ret && value <= tar) {
			size2 = size;
			for (int i = 0; i < size; ++i) {
				out2[i] = out[i];
			}
			ret = value;
			no = 1;
		}
		return 0;
	}

	int temp = 0;
	for (int i = ii; i < len; ++i) {
		temp = temp * 10 + num[i];
		if (value + temp > tar) break;
		out[size++] = temp;
		search(value + temp, i + 1);
		--size;
	}
	return 0;
}

int main()
{
	while (cin >> tar >> sor)
	{
		if (!tar && strcmp(sor, "0") == 0) break;
		for (int i = 0; sor[i] != '\0'; ++i) {
			num[i] = sor[i] - '0';
		}
		len = strlen(sor);

		tmp = 0;
		for (int i = 0; i < len; ++i) {
			tmp = tmp * 10 + num[i];
		}
		if (tmp == tar) {
			cout << tar << ' ' << tmp << endl;
			continue;
		}

		tmp = 0;
		for (int i = 0; i < len; ++i) {
			tmp += num[i];
		}
		if (tmp > tar) {
			cout << "error" << endl;
			continue;
		}

		ret = size = no = tmp = 0;
		for (int i = 0; i < len; ++i) {
			tmp = tmp * 10 + num[i];
			if (tmp > tar) break;
			out[size++] = tmp;
			search(tmp, i + 1);
			--size;
		}

		if (no != 1) {
			cout << "rejected" << endl;
		}
		else {
			cout << ret;
			for (int i = 0; i < size2; ++i) {
				cout << ' ' << out2[i];
			}
			cout << endl;
		}
	}
	return 0;
}
