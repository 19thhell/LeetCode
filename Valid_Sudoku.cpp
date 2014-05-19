class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return validRowAndCol(board) && validSub(board);
    }

    bool validRowAndCol(vector<vector<char> > &board) {
        int row[9], col[9];
        for (int i = 0;i < 9;i++) {
            memset(row, 0, sizeof(row));
            memset(col, 0, sizeof(col));
            for (int j = 0;j < 9;j++) {
                if (board[i][j] != '.')
                    if (++row[board[i][j] - '1'] > 1)
                        return false;
                if (board[j][i] != '.')
                    if (++col[board[j][i] - '1'] > 1)
                        return false;
            }
        }
        return true;
    }

    bool validSub(vector<vector<char> > &board) {
        int center[9][2] = {
            {1, 1}, {1, 4}, {1, 7},
            {4, 1}, {4, 4}, {4, 7},
            {7, 1}, {7, 4}, {7, 7}
        };
        int direct[9][2] = {
            {-1, -1}, {-1,  0}, {-1,  1},
            { 0, -1}, { 0,  0}, { 0,  1},
            { 1, -1}, { 1,  0}, { 1,  1}
        };
        int sub[9];
        for (int i = 0;i < 9;i++) {
            memset(sub, 0, sizeof(sub));
            for (int j = 0;j < 9;j++) {
                char c = board[center[i][0] + direct[j][0]][center[i][1] + direct[j][1]];
                if (c != '.')
                    if (++sub[c - '1'] > 1)
                        return false;
            }
        }
        return true;
    }
};
