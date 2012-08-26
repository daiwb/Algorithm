/*
ZJU 1906 Relatives
00:00.01 444K
*/

#include <iostream> 
#include <cmath> 
using namespace std; 

#define MaxNum 32 

int primes[MaxNum]; 

int Divide(int n)      // return the number of diff primes 
{ 
	int i, cnt = 0; 
    int end = sqrt(double(n));         
	for (i = 2; i <= end; i++) 
	{ 
		if (n%i == 0) 
		{ 
			primes[cnt] = i; 
			while (n%i == 0)    // É¸Ñ¡·¨ 
			{ 
				n /= i; 
			} 
			++cnt; 
		} 
	} 
	if (n != 1) 
	{ 
		primes[cnt] = n; 
		++cnt; 
	} 
	return cnt; 
} 
int main() 
{ 
    int n; 
    while (cin >> n) 
    { 
		if (n == 0) 
			break; 
		if (n == 1) 
        { 
			cout << 0 << endl; 
			continue; 
        } 
		int i; 
		int cnt = Divide(n); 
		int Euler = n; 
		for (i = 0; i < cnt; i++) 
			Euler -= Euler/primes[i]; 
		
		cout << Euler << endl; 
		
	} 
    return 0; 
}