#define L 3
#define N L * L
class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
		int cnt = 0;
		vector<vector<bool> > row(N);
        vector<vector<bool> > col(N);
        vector<vector<bool> > sub(N);
        vector<vector<int> > mapping(N);
        for (int i = 0;i < N;i++) {
            row[i] = vector<bool>(N + 1, true);
            col[i] = vector<bool>(N + 1, true);
            sub[i] = vector<bool>(N + 1, true);
            mapping[i] = vector<int>(N, 0);
        }
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++) {
                mapping[i][j] = i / L * L + j / L;
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = col[j][num] = sub[mapping[i][j]][num] = false;
					cnt++;
                }
            }
		solve(board, cnt, row, col, sub, mapping);
		return;
    }

    bool solve(vector<vector<char> > &board, int cnt, vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &sub, vector<vector<int> > &mapping) {
		if (cnt == N * N)
			return true;
        for (int i = 0;i < N;i++)
            for (int j = 0;j < N;j++)
                if (board[i][j] == '.') {
                    for (int num = 1;num <= N;num++)
						if (row[i][num] && col[j][num] && sub[mapping[i][j]][num]) {
                            board[i][j] = num + '0';
							row[i][num] = col[j][num] = sub[mapping[i][j]][num] = false;
							if (solve(board, cnt + 1, row, col, sub, mapping))
								return true;
							board[i][j] = '.';
							row[i][num] = col[j][num] = sub[mapping[i][j]][num] = true;
						}
					return false;
                }
		return false;
    }
};
