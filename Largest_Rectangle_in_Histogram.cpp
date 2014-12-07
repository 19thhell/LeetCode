
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty())
            return 0;
        stack<pair<int, int> > stk;
        height.push_back(0);
        int p = 0, max_area = 0;
        while (p < height.size()) {
            if (stk.empty() || height[p] > stk.top().first)
                stk.push(make_pair(height[p], p));
            else if (height[p] < stk.top().first) {
                int last = 0;
                while (!stk.empty() && height[p] < stk.top().first) {
                    last = stk.top().second;
                    max_area = max(max_area, stk.top().first * (p - last));
                    stk.pop();
                }
                stk.push(make_pair(height[p], last));
            }
            p++;
        }
        return max_area;
    }
};
