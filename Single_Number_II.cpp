class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int bits[32];
        int result = 0;
        memset(bits, 0, sizeof(bits));
        for (int i = 0;i < 32;i++) {
            for (int j = 0;j < n;j++)
                if ((A[j] >> i) & 1)
                    bits[i] = (bits[i] + 1) % 3;
            result |= (bits[i] << i);
        }
        return result;
    }
};
