class Solution {
public:
    int rob(vector<int> &num) {
        vector<int> best(num.size() + 2, 0);
        for (int i = 2; i < best.size(); i++) {
            best[i] = max(best[i - 2] + num[i - 2], best[i - 1]);
        }
        return best.back();
    }
};
