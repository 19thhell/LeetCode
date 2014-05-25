class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty())
            return;
        m = board.size();
        n = board[0].size();
        for (int i = 0;i < m;i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'P';
                bfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'P';
                bfs(board, i, n - 1);
            }
        }
        for (int i = 0;i < n;i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'P';
                bfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = 'P';
                bfs(board, m - 1, i);
            }
        }
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (board[i][j] == 'P')
                    board[i][j] = 'O';
    }

    void bfs(vector<vector<char>> &board, int si, int sj) {
        int ni, nj;
        queue<int> qi, qj;
        qi.push(si);
        qj.push(sj);
        while (!qi.empty() && !qj.empty()) {
            si = qi.front();
            sj = qj.front();
            qi.pop();
            qj.pop();
            for (int i = 0;i < 4;i++) {
                ni = si + direction[i][0];
                nj = sj + direction[i][1];
                if (0 <= ni && ni < m && 0 <= nj && nj < n)
                    if (board[ni][nj] == 'O') {
                        board[ni][nj] = 'P';
                        qi.push(ni);
                        qj.push(nj);
                    }
            }
        }
    }
private:
    int m;
    int n;
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};
