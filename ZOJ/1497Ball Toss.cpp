/**
 * ZOJ 1497 Ball Toss
 * 2005/04/13 BY adai
 */

#include <iostream>
#include <string>
using namespace std;

#define MAXN 30
#define LEFT 0
#define RIGHT 1

int n, k;
int dir[MAXN];
int visited[MAXN];
int num, step, last;

int Run() {
    cin >> k;
    --k;
    char ch;
    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (ch == 'L') dir[i] = LEFT;
        else dir[i] = RIGHT;
    }
    memset(visited, 0, sizeof(visited));
    num = 1, step = 1, last = 0, visited[k] = 1;
    int tmp;
    while (1) {
        ++step;
        if (dir[k] == LEFT && (last == k + 1 || last == k + 1 - n)) {
            dir[k] = RIGHT;
            last = k--;
            if (k < 0) k = n - 1;
        }
        else if (dir[k] == RIGHT && (k == last + 1 || k == last + 1 - n)) {
            dir[k] = LEFT;
            last = k++;
            if (k == n) k = 0;
        }
        else if (dir[k] == LEFT) {
            dir[k] = RIGHT;
            tmp = last;
            last = k;
            k = tmp - 1;
            if (k < 0) k = n - 1;
        }
        else if (dir[k] == RIGHT) {
            dir[k] = LEFT;
            tmp = last;
            last = k;
            k = tmp + 1;
            if (k == n) k = 0;
        }
        if (!visited[k]) {
            visited[k] = 1;
            ++num;
            if (num == n) break;
        }
    }
    cout << "Classmate " << k + 1 <<" got the ball last after " << step << "
tosses." << endl;
    return 0;
}

int main() {
    while (cin >> n && n) {
        Run();
    }
    return 0;
}
