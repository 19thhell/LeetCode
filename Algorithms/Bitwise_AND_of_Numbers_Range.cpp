class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        for (int bit = 0; bit < 32; bit++) {
            int mod = (1 << bit);
            int seg_m = m / mod, seg_n = n / mod;
            if (seg_m == seg_n)
                result |= ((seg_m & 1) << bit);
        }
        return result;
    }
};
