class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
			return false;
		if (s1 == s2)
			return true;
		int len = s1.size();
		bool dp[len][len][len];
		memset(dp, false, sizeof(bool) * len * len * len);
		for (int k = 1;k <= len;k++)
			for (int i = 0;i <= len - k;i++)
				for (int j = 0;j <= len - k;j++)
					if (k == 1)
						dp[i][j][k] = (s1[i] == s2[j]);
					else {
						for (int l = 1;l < k;l++) {
							if ((dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i][j + k - l][l] && dp[i + l][j][k - l])) {
								dp[i][j][k] = true;
							    break;
							}
						}
					}
		return dp[0][0][len];
    }
};
