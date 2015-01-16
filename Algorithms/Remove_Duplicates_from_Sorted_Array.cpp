class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 1)
            return n;
        int cnt = 1;
        for (int i = 1;i < n;i++)
            if (A[i] != A[i - 1])
                A[cnt++] = A[i];
        return cnt;
    }
};
