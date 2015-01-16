class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0)
            return word2.size();
        if (word2.size() == 0)
            return word1.size();
        vector<vector<int>> mind(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0;i <= word1.size();i++)
            mind[i][0] = i;
        for (int i = 0;i <= word2.size();i++)
            mind[0][i] = i;
        for (int i = 1;i <= word1.size();i++)
            for (int j = 1;j <= word2.size();j++) {
                mind[i][j] = min(mind[i - 1][j] + 1, mind[i][j - 1] + 1);
                if (word1[i - 1] == word2[j - 1])
                    mind[i][j] = min(mind[i - 1][j - 1], mind[i][j]);
                else mind[i][j] = min(mind[i - 1][j - 1] + 1, mind[i][j]);
            }
        return mind[word1.size()][word2.size()];
    }
};
