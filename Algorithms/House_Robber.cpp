class Solution {
public:
    int rob(vector<int> &num) {
        decltype(num.size()) index = 0;
        int best[2] = {0};
        for (const auto &val : num) {
            best[index] = max(best[index] + val, best[index ^ 1]);
            index ^= 1;
        }
        return best[index ^ 1];
    }
};
