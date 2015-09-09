class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k == 0)
            return false;
        queue<int> slide;
        multiset<long> occur;
        for (int i = 0; i < nums.size(); i++) {
            if (slide.size() > k) {
                int num = slide.front();
                slide.pop();
                occur.erase(occur.find(num));
            }
            auto pos = occur.lower_bound((long)nums[i] - (long)t);
            if (pos == occur.end() || *pos > (long)nums[i] + (long)t) {
                slide.push(nums[i]);
                occur.insert(nums[i]);
            }
            else return true;
        }
        return false;
    }
};
