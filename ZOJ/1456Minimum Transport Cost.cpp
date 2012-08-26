#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define MAX 100000
int links[51][51];
void print(int, int, int);

int main(void) {
    int i, j, k, n, x, y, v;
    int tax[51], pay[51][51], first[51][51];
    
    while (scanf("%d", &n) && n) {
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= n; ++j) {
                scanf("%d", &pay[i][j]);
                if (pay[i][j] == -1) pay[i][j] = MAX;
                else {
                    first[i][j] = j;
                    links[i][j] = j;
                }
            }
        }
        
        for (i = 1; i <= n; ++i) {
            scanf("%d", &tax[i]);
        }
        
        for (k = 1; k <= n; ++k) {
            for (i = 1; i <= n; ++i) {
                for (j = 1; j <= n; ++j) {
                    if(pay[i][k] + pay[k][j] + tax[k] < pay[i][j]) {
                        links[i][j] = k;
                        pay[i][j] = pay[i][k] + pay[k][j] + tax[k];
                        first[i][j] = first[i][k];
                    } else if (pay[i][k] + pay[k][j] + tax[k] == pay[i][j] && i != j && i != k && j != k) {
                        v = i;
                        while (first[v][j] == first[v][k]) v = first[v][j];
                        if (first[v][j] > first[v][k]) {
                            first[i][j] = first[i][k];
                            links[i][j] = k;
                        }
                    }
                }
            }
        }
        while (scanf("%d %d", &x, &y)) {
            if (x == -1 && y == -1) break;
            printf("From %d to %d :\n", x, y);
            if (x == y) printf("Path: %d\n", x);
            else {
                printf("Path: %d-->", x);
                print(x, y, links[x][y]);
                printf("%d\n", y);
            }
            printf("Total cost : %d\n\n", pay[x][y]);
        }
    }
    return 0;
}

void print(int x, int y, int point) {
    if (y == point) return;
    else {
        print(x, point, links[x][point]);
        printf("%d-->", point);
        print(point, y, links[point][y]);
    }
}
