class Solution {
public:
    int totalNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> row(n + 1);
        int sum = 0;
        putQueen(row, 1, n, sum);
        return sum;
    }
private:
    void putQueen(vector<int> &row, int n, int total, int &sum) {
        int i, j;
        for (i = 1;i <= total;i++) {
            for (j = 1;j < n;j++)
                if (i == row[j] || n - j == abs(i - row[j]))
                    break;
            if (j == n) {
                if (n == total) {
                    sum++;
                    return;
                }
                row[n] = i;
                putQueen(row, n + 1, total, sum);
                row[n] = 0;
            }
        }
    }
};
