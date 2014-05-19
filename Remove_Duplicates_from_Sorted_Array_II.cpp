class Solution {
public:
    int removeDuplicates(int A[], int n) {
        bool duplicate = false;
        int last = A[0] - 1, cnt = 0;
        for (int i = 0;i < n;i++)
            if (last == A[i]) {
                if (duplicate)
                    continue;
                duplicate = true;
                A[cnt++] = A[i];
            }
            else {
                duplicate = false;
                last = A[i];
                A[cnt++] = A[i];
            }
        return cnt;
    }
};
