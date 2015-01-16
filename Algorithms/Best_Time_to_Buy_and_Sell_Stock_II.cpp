class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (prices.size() <= 1)
            return 0;
        int result = 0;
        for (int i = 1;i < prices.size();i++){
            if (prices[i] > prices[i - 1])
                result += prices[i] - prices[i - 1];
        }
        return result;
    }
};
