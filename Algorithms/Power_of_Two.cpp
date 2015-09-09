class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n > 0 && !(n & 1)) {
            n >>= 1;
        }
        return n == 1;
    }
};
