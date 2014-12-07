class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        string dictionary[10] = {
            " ", "", "abc", "def", 
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };
        generate(result, digits, "", dictionary, 0);
        return result;
    }
private:
    void generate(vector<string> &result, string &digits, string prev, string dictionary[], int pos) {
        if (pos == digits.size()) {
            result.push_back(prev);
            return;
        }
        int index = digits[pos] - '0';
        for (int i = 0;i < dictionary[index].size();i++)
            generate(result, digits, prev + dictionary[index][i], dictionary, pos + 1);
    }
};
