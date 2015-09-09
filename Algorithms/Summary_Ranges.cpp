class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }
        int start = 0, end = 0;
        while (start < nums.size()) {
            while (end < nums.size() - 1 && nums[end + 1] - nums[end] == 1) {
                ++end;
            }
            string range = to_string(nums[start]);
            if (end > start) {
                range += "->";
                range += to_string(nums[end]);
            }
            result.push_back(range);
            start = end + 1;
            end = start;
        }
        return result;
    }
};
