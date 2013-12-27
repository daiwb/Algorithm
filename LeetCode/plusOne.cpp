class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        int add = 1;
        for (int i = n - 1; i >= 0; --i) {
            digits[i]++;
            if (digits[i] == 10) {
                digits[i] = 0;
                add = 1;
            } else {
                add = 0;
                break;
            }
        }
        if (add == 1) {
            digits.push_back(0);
            ++n;
            for (int i = n - 1; i >= 1; --i) digits[i] = digits[i - 1];
            digits[0] = 1;
        }
        return digits;
    }
};