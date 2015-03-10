class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (prices.empty())
            return 0;
        int leftmin = prices[0], result = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < leftmin)
                leftmin = prices[i];
            else if (prices[i] - leftmin > result)
                result = prices[i] - leftmin;
        }
        return result;
    }
};
