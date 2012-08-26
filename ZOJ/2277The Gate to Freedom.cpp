/**
 * ZOJ 2277 The Gate to Freedom
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        double n = N;
        for(; n >= 10; n /= 10);

        double result = 1;
        int i;
        for (i = 1; i <= N; i = i << 1) {
            if((i & N) != 0)
                result *= n;
            n *= n;
            for(; n >= 10; n /= 10);
            for(; result >= 10; result /= 10);
        }
		printf("%d\n", (int)result);
    }
    return 0;
}
