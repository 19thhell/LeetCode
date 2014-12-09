class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0x80000000, sum = 0;
        for (int i = 0;i < n;i++){
            sum = sum < 0 ? A[i] : sum + A[i];
            result = max(result, sum);
        }
        return result;
    }
};
