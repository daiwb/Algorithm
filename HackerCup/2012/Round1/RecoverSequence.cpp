#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

LL checksum(deque<int> arr) {
    LL res = 1;
    REP(i,arr.size()) {
        res = (31 * res + arr[i]) % 1000003;
    }
    return res;
}

int n, idx;
string str;

deque<int> merge_array(deque<int> arr1, deque<int> arr2) {
    deque<int> result;
    while (arr1.size() > 0 && arr2.size() > 0) {
        if (str[idx++] == '1') {
            result.push_back(arr1.front());
            arr1.pop_front();
        } else {
            result.push_back(arr2.front());
            arr2.pop_front();
        }
    }

    REP(i,arr1.size()) result.push_back(arr1[i]);
    REP(i,arr2.size()) result.push_back(arr2[i]);
    return result;
}

deque<int> merge_sort(deque<int> arr) {
    int n = arr.size();
    if (n <= 1) return arr;

    int mid = n / 2;
    
    deque<int> d1, d2;
    FOR(i,0,mid-1) d1.push_back(arr[i]);
    FOR(i,mid,n-1) d2.push_back(arr[i]);

    deque<int> first_half = merge_sort(d1);
    deque<int> second_half = merge_sort(d2);
    return merge_array(first_half, second_half);
}

void run() {
    cin >> n >> str;
    deque<int> que;
    REP(i,n) que.push_back(i);
    idx = 0;
    deque<int> tmp = merge_sort(que);
    deque<int> res(n);
    REP(i,n) {
        res[tmp[i]] = i + 1;
    }
    cout << checksum(res) << endl;
}

int main() {
    int kase;
    cin >> kase;
    FOR(k,1,kase) {
        cout << "Case #" << k << ": ";
        run();
    }
    return 0;
}
