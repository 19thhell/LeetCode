class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        string mapping[10] = {
            " ", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        generate(result, digits, "", mapping, 0);
        return result;
    }

    void generate(vector<string> &result, string &digits, string prev, string mapping[], int pos) {
        if (pos == digits.size()) {
            result.push_back(prev);
            return;
        }
        int index = digits[pos] - '0';
        for (int i = 0;i < mapping[index].size();i++) {
            string tmp = prev;
            tmp += mapping[index][i];
            generate(result, digits, tmp, mapping, pos + 1);
        }
        return;
    }
};
