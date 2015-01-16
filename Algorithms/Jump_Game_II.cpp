class Solution {
public:
    int jump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int last = 0;
        vector<int> step(n, 0);
        for (int i = 0;i < n - 1;i++) {
            for (int j = last + 1;j <= A[i] + i && j < n;j++)
                step[j] = step[i] + 1;
            last = max(last, A[i] + i);
        }
        return step[n - 1];
    }
};
