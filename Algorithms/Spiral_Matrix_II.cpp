class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result(n);
        if (n == 0)
            return result;
        for (int i = 0;i < n;i++) {
            result[i] = vector<int>(n);
            for (int j = 0;j < n;j++)
                result[i][j] = -1;
        }
        int mov_x[4] = {0, 1, 0, -1};
        int mov_y[4] = {1, 0, -1, 0};
        int drc = 0, cnt = 1, x = 0, y = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++) {
                result[x][y] = cnt++;
                x += mov_x[drc];
                y += mov_y[drc];
                if (x >= n || y >= n || x < 0 || y < 0 || result[x][y] != -1) {
                    x -= mov_x[drc];
                    y -= mov_y[drc];
                    drc = (drc + 1) % 4;
                    x += mov_x[drc];
                    y += mov_y[drc];
                }
            }
        return result;
    }
};
