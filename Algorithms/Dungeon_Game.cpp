class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int> > health(row, vector<int>(col, 0));
        health[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
        for (int i = row - 2; i >= 0; i--)
        {
            health[i][col - 1] = max(1, health[i + 1][col - 1] - dungeon[i][col - 1]);
        }
        for (int j = col - 2; j >= 0; j--)
        {
            health[row - 1][j] = max(1, health[row - 1][j + 1] - dungeon[row - 1][j]);
        }
        for (int i = row - 2; i >= 0; i--)
        {
            for (int j = col - 2; j >= 0; j--)
            {
                health[i][j] = max(1, min(health[i + 1][j], health[i][j + 1]) - dungeon[i][j]);
            }
        }
        return health[0][0];
    }
};
