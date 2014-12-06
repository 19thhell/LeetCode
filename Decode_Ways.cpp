class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> result(s.size());
        for (int i = 0;i < s.size();i++) {
            result[i] = 0;
            if (i == 0) {
                if ('1' <= s[i] && s[i] <= '9')
                    result[i] = 1;
            }
            else {
                string sub(s, i - 1, 2);
                if ("10" <= sub && sub <= "26")
                    result[i] += (i - 2 >= 0) ? result[i - 2] : 1;
                if ('1' <= s[i] && s[i] <= '9')
                    result[i] += result[i - 1];
            }
        }
        return result.back();
    }
};
