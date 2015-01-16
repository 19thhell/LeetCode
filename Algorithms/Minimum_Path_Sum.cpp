class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > dist(m, vector<int>(n));
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++)
                dist[i][j] = grid[i][j];
        }
        for (int i = 1;i < n;i++)
            dist[0][i] += dist[0][i - 1];
        for (int i = 1;i < m;i++)
            dist[i][0] += dist[i - 1][0];
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                dist[i][j] += min(dist[i - 1][j], dist[i][j - 1]);
        return dist[m - 1][n - 1];
    }
};
