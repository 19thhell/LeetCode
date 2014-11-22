class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size(), result;
        vector<vector<int> > height(row, vector<int>(col, 0));
        for (int i = 0;i < col;i++)
            if (matrix[0][i] == '1')
                height[0][i] = 1;
        result = largestRectangleArea(height[0]);
        for (int i = 1;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (matrix[i][j] == '1')
                    height[i][j] = height[i - 1][j] + 1;
            }
            result = max(result, largestRectangleArea(height[i]));
        }
        return result;
    }
private:
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
