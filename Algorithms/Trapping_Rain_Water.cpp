class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 2)
            return 0;
        int result = 0, max_h = 0, *left_h = new int[n];
        int h, left, right;
        left_h[0] = 0;
        max_h = A[0];
        for (int i = 1;i < n;i++) {
            left_h[i] = max_h;
            if (max_h < A[i])
                max_h = A[i];
        }
        max_h = A[n - 1];
        for (int i = n - 2;i >= 0;i--) {
            left = left_h[i];
            right = max_h;
            h = min(left, right);
            if (h > A[i])
                result += h - A[i];
            if (max_h < A[i])
                max_h = A[i];
        }
        return result;
    }
};
