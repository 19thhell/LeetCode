class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.size() < T.size())
            return 0;
        vector<vector<int> > methods(S.size() + 1, vector<int>(T.size() + 1, 0));
        for (int i = 0;i <= S.size();i++)
            methods[i][0] = 1;
        for (int i = 1;i <= S.size();i++)
            for (int j = 1; j <= T.size();j++) {
                methods[i][j] = methods[i - 1][j];
                if (S[i - 1] == T[j - 1])
                    methods[i][j] += methods[i - 1][j - 1];
            }
        return methods[S.size()][T.size()];
    }
};
