class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (strs.empty())
            return "";
        string result = strs[0];
        for (string s : strs)
            result = common(result, s);
        return result;
    }
private:
    string common(string &a, string &b) {
        int maxl = min(a.size(), b.size()), p;
        for (p = 0;p < maxl;p++)
            if (a[p] != b[p])
                break;
        return a.substr(0, p);
    }
};
