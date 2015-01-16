class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1)
            return 0;
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        vector<int> cut(s.size() + 1);
        for (int i = 0;i <= s.size();i++)
            cut[i] = s.size() - 1 - i;
        for (int i = s.size() - 1;i >= 0;i--) {
            for (int j = i;j < s.size();j++) {
                if ((j - i < 2 || isPalindrome[i + 1][j - 1]) && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                    cut[i] = min(cut[i], cut[j + 1] + 1);
                }
            }
        }
        return cut[0];
    }
};
