class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> occur;
        for (int i = 0; i < nums.size(); i++) {
            if (occur.find(nums[i]) != occur.end() && (i - occur[nums[i]] <= k))
                return true;
            occur[nums[i]] = i;
        }
        return false;
    }
};
