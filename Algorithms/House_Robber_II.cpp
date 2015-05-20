class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int index = 1;
        int best[2] = {nums[0], 0};
        for (int i = 1; i < nums.size() - 1; i++) {
            best[index] = max(best[index] + nums[i], best[index ^ 1]);
            index ^= 1;
        }
        int max1 = best[index ^ 1];
        best[0] = best[1] = 0;
        index = 1;
        for (int i = 1; i < nums.size(); i++) {
            best[index] = max(best[index] + nums[i], best[index ^ 1]);
            index ^= 1;
        }
        int max2 = best[index ^ 1];
        return max(max1, max2);
    }
};
