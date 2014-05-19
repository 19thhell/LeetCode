class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_set<int> hash_set;
        int max_cnt = 0, cnt = 0;
        for (int i = 0;i < num.size();i++)
            hash_set.insert(num[i]);
        for (int i = 0;i < num.size();i++) {
            cnt = calculate(hash_set, num[i]);
            if (max_cnt < cnt)
                max_cnt = cnt;
        }
        return max_cnt;
    }

    int calculate(unordered_set<int> &hash_set, int target) {
        int cnt = 1, left = target - 1, right = target + 1;
        hash_set.erase(target);
        while (hash_set.count(left) > 0) {
            cnt++;
            hash_set.erase(left--);
        }
        while (hash_set.count(right) > 0) {
            cnt++;
            hash_set.erase(right++);
        }
        return cnt;
    }
};
