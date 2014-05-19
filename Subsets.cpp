class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> sub;
        int depth = 0;
        for (int i = 0;i <= S.size();i++)
            generate(S, sub, result, 0, i);
        return result;
    }

    void generate(vector<int> &S, vector<int> &sub, vector<vector<int> > &result, int head, int max_depth) {
        if (sub.size() == max_depth) {
            result.push_back(sub);
            return;
        }
        for (int i = head;i < S.size();i++) {
            sub.push_back(S[i]);
            generate(S, sub, result, i + 1, max_depth);
            sub.pop_back();
        }
    }
};
