class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t left = 0x80000000, right = 1;
        while (left > right)
        {
            if ((bool)(n & left) ^ (bool)(n & right))
            {
                n ^= (left | right);
            }
            left >>= 1;
            right <<= 1;
        }
        return n;
    }
};
