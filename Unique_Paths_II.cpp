class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m, n;
        m = obstacleGrid.size();
        if (!m)
            return 0;
        n = obstacleGrid[0].size();
        if (!n)
            return 0;
        int result[101][101];
        memset(result, 0, sizeof(result));
        result[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1;i < m;i++)
            result[i][0] = obstacleGrid[i][0] == 1 ? 0 : result[i - 1][0];
        for (int i = 1;i < n;i++)
            result[0][i] = obstacleGrid[0][i] == 1 ? 0 : result[0][i - 1];
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                result[i][j] = obstacleGrid[i][j] == 1 ? 0 : result[i - 1][j] + result[i][j - 1];
        return result[m - 1][n - 1];
    }
};
