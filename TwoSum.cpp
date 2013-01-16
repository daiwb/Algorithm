#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<pair<int, int> > mm;
        for (int i = 0; i < n; ++i) mm.push_back(make_pair(numbers[i], i + 1));
        sort(mm.begin(), mm.end());
        int lp = 0, rp = n - 1;
        while (lp < rp) {
            int sum = mm[lp].first + mm[rp].first;
            if (sum == target) break;
            else if (sum < target) ++lp;
            else --rp;
        }
        vector<int> ret;
        ret.push_back(min(mm[lp].second, mm[rp].second));
        ret.push_back(max(mm[lp].second, mm[rp].second));
        return ret;
    }
};
