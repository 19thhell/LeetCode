class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (nRows == 1)
            return s;
        vector<string> pattern(nRows);
        int direct = 1, row = 0;
        string result;
        for (int i = 0;i < s.size();i++) {
            pattern[row] += s[i];
            if (direct) {
                if (row == nRows - 1) {
                    direct = 0;
                    row--;
                }
                else row++;
            }
            else {
                if (row == 0) {
                    direct = 1;
                    row++;
                }
                else row--;
            }
        }
        for (int i = 0;i < pattern.size();i++)
            result += pattern[i];
        return result;
    }
};
