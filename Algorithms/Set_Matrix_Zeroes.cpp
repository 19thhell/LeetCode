class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool first_row_zero = false;
        bool first_col_zero = false;
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        if (n == 0)
            return;
        for (int i = 0;i < n;i++)
            if (matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }
        for (int i = 0;i < m;i++)
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (first_row_zero)
            for (int i = 0;i < n;i++)
                matrix[0][i] = 0;
        if (first_col_zero)
            for (int i = 0;i < m;i++)
                matrix[i][0] = 0;
    }
};
