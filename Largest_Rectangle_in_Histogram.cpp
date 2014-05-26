class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty())
            return 0;
        stack<pair<int, int> > stk;
        int p = 0, max_area = 0, last;
        while (p < height.size()) {
            if (stk.empty() || height[p] > stk.top().first)
                stk.push(make_pair(height[p], p));
            else if (height[p] < stk.top().first) {
                last = 0;
                while (!stk.empty() && height[p] < stk.top().first) {
                    last = stk.top().second;
                    max_area = max(max_area, stk.top().first * (p - stk.top().second));
                    stk.pop();
                }
                stk.push(make_pair(height[p], last));
            }
            p++;
        }
        while (!stk.empty()) {
            max_area = max(max_area, stk.top().first * (p - stk.top().second));
            stk.pop();
        }
        return max_area;
    }
};
