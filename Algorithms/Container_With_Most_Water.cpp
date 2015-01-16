class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = height.size() - 1, result = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                result = max(result, (right - left) * height[left]);
                left++;
            }
            else {
                result = max(result, (right - left) * height[right]);
                right--;
            }
        }
        return result;
    }
};
