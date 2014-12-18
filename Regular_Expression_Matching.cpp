class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        vector<vector<bool> > match(strlen(s) + 1, vector<bool>(strlen(p) + 1, false));
        match[strlen(s)][strlen(p)] = true;
        for (int i = strlen(p) - 2;i >= 0;i--) {
            if (p[i + 1] == '*') {
                match[strlen(s)][i] = match[strlen(s)][i + 2];
            }
        }
        for (int j = strlen(p) - 1;j >= 0;j--) {
            if (p[j] != '*') {
				for (int i = strlen(s) - 1;i >= 0;i--) {
					if (p[j + 1] != '*') {
						match[i][j] = (s[i] == p[j] || p[j] == '.') ? match[i + 1][j + 1] : false;
					}
					else if (match[i][j + 2])
						match[i][j] = true;
					else {
						match[i][j] = (s[i] == p[j] || p[j] == '.') ? match[i + 1][j] : false;
					}
				}
			}
        }
        return match[0][0];
    }
};
