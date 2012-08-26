#include <cstdio>
#include <string>
using namespace std;

typedef unsigned char byte;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define INF 255

int n, m, total, n3;
int ms[75];
int ct[1<<7];
int ht[1<<7];
byte mm[75][1<<7][1<<7];
int states[2187], masks[2187];
int valids[2187];
int idx;

byte dp(int level, int mask, int state) {
    byte& ret = mm[level][mask][state];
    if (ret != INF) return ret;

    ret = INF - 1;

    if (level == m) {
        if (mask) return ret;
        else return ret = 0;
    }

    REP(ss,idx) {
        int s2 = states[valids[ss]];
        int m2 = masks[valids[ss]];

        // If there're two consecutive vertical "0"s, skip.
        if ((s2 | state) != total - 1) continue;

        if (m2 & ms[level]) continue;
        if (mask & ~m2) continue;

        int st = (m2 | ~s2 | ms[level]) & (total - 1);

        int cnt = ht[st];
        if (cnt == -1) continue;

        int m3 = (m2 & ~mask);
        cnt += ct[m3];

        byte d = dp(level + 1, m3, s2);
        if (d != INF - 1) {
            d += cnt;
            if (d < ret) ret = d;
        }
    }

    return ret;
}

int main() {
    scanf("%d %d", &m, &n);
    total = 1 << n;
    n3 = 1;
    REP(i,n) n3 = (n3 << 1) + n3;
    
    memset(ms, 0, sizeof(ms));
    REP(i,m) {
        char ch[10];
        scanf("%s", ch);
        REP(j,n) if (ch[j] == '*') {
            ms[i] |= (1 << j);
        }
    }
    
    REP(i,total) {
        // ct[i] stores how many "1"s are in binary representation of i.
        int t = i;
        ct[i] = 0;
        while (t) {
            ++ct[i];
            t &= (t - 1);
        }

        // ht[i] stores how many horizontal 1x2 chocolates can be placed when the state is i.
        // If ht[i] is -1, then the state is invalid.
        int hn = n - ct[i];
        if (hn & 1) {
            ht[i] = -1;
            continue;
        }
        ht[i] = hn >> 1;

        int num = 0;
        REP(j,n) {
            if (i & (1 << j)) {
                if (num & 1) {
                    ht[i] = -1;
                    break;
                }
                num = 0;
            } else {
                ++num;
            }
        }
        if (num & 1) ht[i] = -1;
    }

    // states[i] and masks[i] store corresponding values in ternary representation of i.
    memset(states, 0, sizeof(states));
    memset(masks, 0, sizeof(masks));

    // valids stores the valid ternary representations - no two consecutive "0"s.
    idx = 0;
    REP(i,n3) {
        int t = i;
        REP(j,n) {
            if (t % 3 == 1) {
                states[i] |= (1 << j);
            } else if (t % 3 == 2) {
                states[i] |= (1 << j);
                masks[i] |= (1 << j);
            }
            t /= 3;
        }

        int tmp = (states[i] | (states[i] >> 1));
        if (tmp == total - 1 || tmp == ((total - 1) >> 1)) {
            valids[idx++] = i;
        }
    }

    memset(mm, -1, sizeof(mm));
    byte res = dp(0, 0, total - 1);
    printf("%d\n", res);
    
    return 0;
}
