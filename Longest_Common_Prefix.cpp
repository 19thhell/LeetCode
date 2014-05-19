class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (strs.empty())
            return "";
        string s;
        for (int i = 0;i < strs[0].size();i++) {
            for (int j = 1;j < strs.size();j++)
                if (i > strs[j].size() || strs[j][i] != strs[j - 1][i])
                    return s;
            s += strs[0][i];
        }
        return s;
    }
};
