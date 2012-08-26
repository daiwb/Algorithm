//ac

#include <iostream>
#include <string>
using namespace std;

const long Limit = 10001;

struct Tdata_node  {
	int usenum, mintimes;
};

long n;
bool hash[Limit];
long super_prime[Limit];
long ps, sps;
Tdata_node data[Limit];

void prepare() {
	long i, j;
	ps = 0;   sps = 0;
	memset(hash, true, sizeof(hash));
	hash[1] = false;
	for (i = 2; i <= 10000; i ++)
		if (hash[i]) {
			ps ++;
			for (j = i + i; j <= 10000; j += i) hash[j] = false;
			if (hash[ps])   {
				sps ++;
				super_prime[sps] = i;
			}
		}
}

void work() {
	long i, k;

	cin >> n;
	memset(data, 0, sizeof(data));
	for (i = 1; i <= n; i ++)
		data[i]. mintimes = -1;

	for (k = 1; k <= sps; k ++)
		for (i = 0; i <= n - super_prime[k]; i ++)
			if (data[i]. mintimes >= 0)
				if ((data[i + super_prime[k]]. mintimes == -1) ||
						(data[i + super_prime[k]]. mintimes >= data[i]. mintimes + 1))  {
					data[i + super_prime[k]]. mintimes = data[i]. mintimes + 1;
					data[i + super_prime[k]]. usenum   = super_prime[k];
				}
}

void print()   {
	int outseq[Limit];
	int total, tmp, i;

	if (data[n]. mintimes == -1)
		cout << 0 << endl;
	else    {
		total = 0;
		tmp = n;
		while (tmp != 0) {
			total ++;
			outseq[total] = data[tmp]. usenum;
			tmp -= data[tmp]. usenum;
		}
		cout << total << endl;
		for (i = 1; i <= total - 1; i ++)
			cout << outseq[i] << " ";
		cout << outseq[total] << endl;
	}
}

int main()  {
	prepare();
	work();
	print();
	return 0;
}
