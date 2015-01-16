class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int x = 0, y = 0, m = matrix.size();
        if (m == 0)
            return result;
        int n = matrix[0].size();
        if (n == 0)
            return result;
        int total = m * n, direct = 0;
        vector<bool> visit(total, false);
        for (int i = 0;i < total;i++) {
            visit[x * n + y] = true;
            result.push_back(matrix[x][y]);
            switch (direct) {
                case 0:
                    goEast(visit, x, y, m, n, direct);
                    break;
                case 1:
                    goSouth(visit, x, y, m, n, direct);
                    break;
                case 2:
                    goWest(visit, x, y, m, n, direct);
                    break;
                case 3:
                    goNorth(visit, x, y, m, n, direct);
                    break;
            }
        }
        return result;
    }

    inline void goEast(vector<bool> &visit, int &x, int &y, int &m, int &n, int &direct) {
        if (y < n - 1 && !visit[x * n + y + 1])
            y++;
        else {
            x++;
            direct = 1;
        }
    }

    inline void goSouth(vector<bool> &visit, int &x, int &y, int &m, int &n, int &direct) {
        if (x < m - 1 && !visit[(x + 1) * n + y])
            x++;
        else {
            y--;
            direct = 2;
        }
    }

    inline void goWest(vector<bool> &visit, int &x, int &y, int &m, int &n, int &direct) {
        if (y > 0 && !visit[x * n + y - 1])
            y--;
        else {
            x--;
            direct = 3;
        }
    }

    inline void goNorth(vector<bool> &visit, int &x, int &y, int &m, int &n, int &direct) {
        if (x > 0 && !visit[(x - 1) * n + y])
            x--;
        else {
            y++;
            direct = 0;
        }
    }
};
