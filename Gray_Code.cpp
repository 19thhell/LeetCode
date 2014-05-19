class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> a((1 << n));
        for (int i = 0;i < a.size();i++)
            a[i] = (i >> 1) ^ i;
        return a;
    }
};
