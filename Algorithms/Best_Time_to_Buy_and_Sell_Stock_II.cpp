class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (prices.size() < 2)
            return 0;
        int result = 0;
        for (int i = 0;i < prices.size() - 1;i++){
            int leftmin = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            result += prices[i] - leftmin;
        }
        return result;
    }
};
