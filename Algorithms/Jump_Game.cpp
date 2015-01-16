class Solution {
public:
    bool canJump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int last = 0;
        for (int i = 0;i < n - 1;i++) {
            last = max(last, i + A[i]);
            if (last >= n - 1 || last <= i)
                break;
        }
        return last >= n - 1;
    }
};
