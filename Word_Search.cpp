class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || word.size() == 0)
            return false;
        m = board.size();
        n = board[0].size();
        vector<vector<bool> > visit(m);
        for (int i = 0;i < m;i++)
            visit[i] = vector<bool>(n, false);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    if (dfs(board, word, visit, 1, i, j))
                        return true;
                    visit[i][j] = false;
                }
        return false;
    }

    bool dfs(vector<vector<char> > &board, string &word, vector<vector<bool> > &visit, int pos, int si, int sj) {
        if (pos >= word.size())
            return true;
        int ni, nj;
        for (int i = 0;i < 4;i++) {
            ni = si + x[i];
            nj = sj + y[i];
            if (ni >= 0 && ni < m && nj >=0 && nj < n && !visit[ni][nj] && board[ni][nj] == word[pos]) {
                visit[ni][nj] = true;
                if (dfs(board, word, visit, pos + 1, ni, nj))
                    return true;
                visit[ni][nj] = false;
            }
        }
        return false;
    }
private:
    int m;
    int n;
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, -1, 0, 1};
};
