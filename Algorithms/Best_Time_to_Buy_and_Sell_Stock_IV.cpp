class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.size() < 2 || k == 0)
            return 0;
        vector<int> profits;
        stack<pair<int, int> > vp_pairs;
        int v = 0, p = 0, n = prices.size();
        while (p < n)
        {
			//Find next valley-peak pair
            for (v = p; v < n - 1 && prices[v] >= prices[v + 1]; v++);
            for (p = v + 1; p < n && prices[p] >= prices[p - 1]; p++);
			//If current valley is lower than previous valley, these two transactions can not be combine to gain a better profit
            while (!vp_pairs.empty() && prices[v] < prices[vp_pairs.top().first])
            {
                profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
                vp_pairs.pop();
            }
			//If v1 <= v2 && p1 <= p2, store both (v1, p2) and (v2, p1) as candidate transactions
            while (!vp_pairs.empty() && prices[p - 1] >= prices[vp_pairs.top().second - 1])
            {
                profits.push_back(prices[vp_pairs.top().second - 1] - prices[v]);
                v = vp_pairs.top().first;
                vp_pairs.pop();
            }
            vp_pairs.push(pair<int, int>(v, p));
        }
        while (!vp_pairs.empty())
        {
            profits.push_back(prices[vp_pairs.top().second - 1] - prices[vp_pairs.top().first]);
            vp_pairs.pop();
        }
        make_heap(profits.begin(), profits.end());
        int result = 0;
        for (int i = 0; !profits.empty() && (i < k); i++)
        {
            pop_heap(profits.begin(), profits.end());
            result += profits.back();
            profits.pop_back();
        }
        return result;
    }
};
