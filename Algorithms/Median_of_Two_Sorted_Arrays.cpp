class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n)
            return findMedianSortedArrays(B, n, A, m);
        int left = 0, right = m, fac = (m + n + 1) / 2;
        while (left <= right) {
            int p = (left + right) / 2, q = fac - p;
            if (p < m && q > 0 && A[p] < B[q - 1])
                left = p + 1;
            else if (p > 0 && q < n && A[p - 1] > B[q])
                right = p - 1;
            else {
                int max_left;
                if (p == 0)
                    max_left = B[q - 1];
                else if (q == 0)
                    max_left = A[p - 1];
                else max_left = max(A[p - 1], B[q - 1]);
                if ((m + n) & 1)
                    return max_left;
				int min_right;
                if (p == m)
                    min_right = B[q];
                else if (q == n)
                    min_right = A[p];
                else min_right = min(A[p], B[q]);
                return ((double)(max_left + min_right)) / 2;
            }
        }
    }
};
