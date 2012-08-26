/*zju 2028 How Many Left
00:00.01 436k
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char a[300], b[300];
	int n, m, p; 
	while(1){
		cin >> a >> b;
		if(cin.fail()) break;

		if(strcmp(a, "1") == 0){
			cout << b << endl;
			continue;
		}
		if(strcmp(b, "1") == 0){
			cout << a << endl;
			continue;
		}

		int lena = strlen(a);
		int lenb = strlen(b);

		n = m = 0;
		int count = 1;
		for(int i = lena - 1; i >= 0; i --){
			n += (a[i] - '0') * count;
			count *= 10;
			if(count == 1000) break;
		}
		count = 1;
		for(int i = lenb - 1; i >= 0; i --){
			m += (b[i] - '0') * count;
			count *= 10;
			if(count ==	1000) break;
		}

		p = m * n; 
		if(p % 4 == 0 && p % 8 != 0) 
			cout << 4 << endl; 
		else 
			if(p % 4 == 0) 
				cout << "Yes" << endl; 
			else 
				cout << p % 4 << endl; 
	} 
	return 0; 
}
