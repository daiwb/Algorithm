#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        vector<int> prev(len);
        map<char, int> mp;
        map<char, int>::iterator itr;
        for (int i = 0; i < len; ++i) {
            itr = mp.find(s[i]);
            if (itr == mp.end()) prev[i] = -1;
            else prev[i] = mp[s[i]];
            mp[s[i]] = i;
        }
        int ret = 1, add = 0;
        for (int i = len - 1; i >= 0; --i) {
            int p = prev[i];
            if (p == -1) {
                ++add;
                ret = max(ret, add);
                continue;
            }
            if (i - p + add <= ret) {
                add = 0;
                continue;
            }
            for (int j = i - 1; j > p; --j) {
                if (prev[j] > p) p = prev[j];
            }
            ret = max(ret, i - p + add);
            add = 0;
        }
        return ret;
    }
};
