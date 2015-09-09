class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> occur;
        for (auto num : nums) {
            if (occur.find(num) == occur.end())
                occur.insert(num);
            else return true;
        }
        return false;
    }
};
