//Solution 1: rotate by layer
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        for (int i = 0;i < matrix.size() / 2;i++)
            rotateLayer(matrix, i);
    }

    void rotateLayer(vector<vector<int> > &matrix, int depth) {
        int n = matrix.size() - depth - 1;
        for (int i = depth;i < n;i++) {
            int tmp = matrix[depth][i];
            swap(tmp, matrix[i][n]);
            swap(tmp, matrix[n][n + depth - i]);
            swap(tmp, matrix[n + depth - i][depth]);
            swap(tmp, matrix[depth][i]);
        }
    }
};

//Solution 2: transposition, then symmetric
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = matrix.size();
        int m = (n - 1) / 2;
        for (int i = 0;i < n;i++)
            for (int j = i + 1;j < n;j++)
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j <= m;j++)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }
};
