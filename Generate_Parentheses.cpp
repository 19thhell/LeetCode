class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        string s;
        if (n)
            Combination(result, s, 0, n, 0, 0);
        return result;
    }

    void combination(vector<string> &result, string &s, int depth, int n, int left, int right) {
        if (depth == 2 * n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            s += "(";
            combination(result, s, depth + 1, n, left + 1, right);
            s.resize(s.size() - 1);
        }
        if (left > right) {
            s += ")";
            combination(result, s, depth + 1, n, left, right + 1);
            s.resize(s.size() - 1);
        }
    }
};
