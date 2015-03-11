class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;
        int n = prices.size(), valley = prices[0], peak = prices[n - 1], past = 0;
        vector<int> future(n, 0);
        for (int i = n - 2;i >= 0;i--) {
            future[i] = max(peak - prices[i], future[i + 1]);
            if (peak < prices[i])
                peak = prices[i];
        }
        int result = future[0];
        for (int i = 1;i < n;i++) {
            if (past < prices[i] - valley)
                past = prices[i] - valley;
            else if (valley > prices[i])
                valley = prices[i];
            result = max(result, past + future[i]);
        }
        return result;
    }
};
