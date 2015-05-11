class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = 0, n = nums.size(), min_len = 0, sum = 0;
        while (end < n) {
            while (sum < s && end < n) {
                sum += nums[end++];
            }
            while (sum >= s && start < end) {
                if (min_len == 0 || min_len > end - start)
                    min_len = end - start;
                sum -= nums[start++];
            }
        }
        return min_len;
    }
};
