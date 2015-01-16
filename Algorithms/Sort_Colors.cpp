class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 1)
            return;
        int i = 0, j = n - 1, cur = 0;
        while (cur <= j) {
            if (A[cur] == 0)
                if (cur > i)
                    swap(A[cur], A[i++]);
                else {
                    cur++;
                    i++;
                }
            else if (A[cur] == 2)
                if (cur < j)
                    swap(A[cur], A[j--]);
                else return;
            else cur++;
        }
    }
};
