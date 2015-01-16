class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int *pA = A + m - 1, *pB = B + n - 1, *pMerge = A + m + n - 1;
        while (pA >= A && pB >= B){
            if (*pA > *pB)
                *pMerge-- = *pA--;
            else *pMerge-- = *pB--;
        }
        while (pB >= B)
            *pMerge-- = *pB--;
    }
};
