class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        int result[10000];
        for (int i = 0;i < s.size();i++) {
            result[i] = 0;
            if (i == 0) {
                if ('1' <= s[i] && s[i] <= '9')
                    result[i] = 1;
            }
            else {
                string tmp(s, i - 1, 2);
                if ("10" <= tmp && tmp <= "26")
                    result[i] += (i - 2 >= 0) ? result[i - 2] : 1;
                if ('1' <= s[i] && s[i] <= '9')
                    result[i] += (i - 1 >= 0) ? result[i - 1] : 1;
            }
        }
        return result[s.size() - 1];
    }
};
