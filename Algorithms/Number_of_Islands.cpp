class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty())
            return 0;
        int islands = 0, row = grid.size(), col = grid[0].size();
        const int neighbor[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		queue<pair<int, int>> bfs;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    bfs.push(pair<int, int>(i, j));
                    grid[i][j] = '0';
                    while (!bfs.empty()) {
                        int row_o = bfs.front().first, col_o = bfs.front().second;
                        bfs.pop();
                        for (auto &direct : neighbor) {
                            int row_n = row_o + direct[0], col_n = col_o + direct[1];
                            if (row_n >= 0 && row_n < row && col_n >= 0 && col_n < col && grid[row_n][col_n] == '1') {
                                bfs.push(pair<int, int>(row_n, col_n));
                                grid[row_n][col_n] = '0';
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
};
