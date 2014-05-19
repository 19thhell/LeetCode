class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        vector<int> c;
        dfs(result, c, 1, n, k);
        return result;
    }

    void dfs(vector<vector<int> > &result, vector<int> &c, int s, int n, int k) {
        if (c.size() == k) {
            result.push_back(c);
            return;
        }
        for (int i = s;i <= n;i++) {
            c.push_back(i);
            dfs(result, c, i + 1, n, k);
            c.pop_back();
        }
    }
};
