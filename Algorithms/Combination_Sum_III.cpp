class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> seq;
        int occur[10]{false};
        dfs(result, seq, occur, k, n, 0, 0);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& seq, int occur[], int k, int n, int sum, int prev) {
        if (seq.size() == k && n == sum) {
            result.push_back(seq);
            return;
        }
        for (int i = prev + 1; i <= 9; i++) {
            if (!occur[i] && i + sum <= n) {
                occur[i] = true;
                seq.push_back(i);
                dfs(result, seq, occur, k, n, sum + i, i);
                seq.pop_back();
                occur[i] = false;
            }
        }
    }
};
