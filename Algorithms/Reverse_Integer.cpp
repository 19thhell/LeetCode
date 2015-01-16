class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = 0;
        bool isNeg = x > 0 ? false : true;
        x = abs(x);
        while (x > 0){
            n = n * 10 + x % 10;
            x /= 10;
        }
        return isNeg ? -n : n;
    }
};
