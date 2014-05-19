class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        digits.back()++;
        for (int i = digits.size() - 1;i >= 0;i--) {
            if (digits[i] > 9) {
                if (i > 0) {
                    digits[i - 1]++;
                    digits[i] = 0;
                }
                else {
                    digits[0] = 0;
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            else break;
        }
        return digits;
    }
};
