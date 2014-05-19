class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > result;
        vector<int> row(n + 1);
        putQueen(row, 1, n, result);
        return result;
    }

    void putQueen(vector<int> &row, int n, int total, vector<vector<string> > &result) {
        int i, j;
        for (i = 1;i <= total;i++) {
            row[n] = i;
            for (j = 1;j < n;j++)
                if (i == row[j] || n - j == abs(i - row[j]))
                    break;
            if (j == n) {
                if (n == total) {
                    vector<string> board;
                    string line;
                    for (int k = 1;k <= total;k++) {
                        line = "";
                        for (int m = 1;m <= total;m++)
                            if (m == row[k])
                                line += "Q";
                            else line += ".";
                        board.push_back(line);
                    }
                    result.push_back(board);
                    return;
                }
                putQueen(row, n + 1, total, result);
                row[n] = 0;
            }
        }
    }
};
