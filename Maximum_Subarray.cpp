class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = -999999, sum = 0;
        for (int i = 0;i < n;i++){
            sum = sum < 0 ? A[i] : sum + A[i];
            if (result < sum)
                result = sum;
        }
        return result;
    }
};
