class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n <= 0)
            return 1;
        const int max_int = n + 2;
        for (int i = 0;i < n;i++)
            if (A[i] <= 0)
                A[i] = max_int;
        for (int i = 0;i < n;i++) {
            int positive = abs(A[i]);
            if (positive <= n)
                A[positive - 1] = -abs(A[positive - 1]);
        }
        for (int i = 0;i < n;i++)
            if (A[i] > 0)
                return i + 1;
        return n + 1;
    }
};
