class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int n = prices.size(), result = 0, min_p = prices[0], max_p = prices[n - 1];
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1;i < n;i++) {
            left[i] = max(prices[i] - min_p, left[i - 1]);
            min_p = min(prices[i], min_p);
        }
        for (int i = n - 2;i >= 0;i--) {
            right[i] = max(max_p - prices[i], right[i + 1]);
            max_p = max(prices[i], max_p);
        }
        for (int i = 0;i < n;i++)
            result = max(result, left[i] + right[i]);
        return result;
    }
};
