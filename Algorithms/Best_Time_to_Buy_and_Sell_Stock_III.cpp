class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int n = prices.size(), base = prices[0], peak = prices[n - 1], past = 0, result;
        vector<int> future(n, 0);
        for (int i = n - 2;i >= 0;i--) {
            future[i] = max(peak - prices[i], future[i + 1]);
            peak = max(prices[i], peak);
        }
        result = future[0];
        for (int i = 1;i < n;i++) {
            past = max(prices[i] - base, past);
            base = min(prices[i], base);
            result = max(result, past + future[i]);
        }
        return result;
    }
};
