class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_set<int> occurence;
        int max_cnt = 0, cnt = 0;
        for (int i = 0;i < num.size();i++)
            occurence.insert(num[i]);
        for (int i = 0;i < num.size();i++) {
            cnt = calculate(occurence, num[i]);
            if (max_cnt < cnt)
                max_cnt = cnt;
        }
        return max_cnt;
    }
private:
    int calculate(unordered_set<int> &occurence, int target) {
        int cnt = 1, left = target - 1, right = target + 1;
        occurence.erase(target);
        while (occurence.count(left)) {
            cnt++;
            occurence.erase(left--);
        }
        while (occurence.count(right)) {
            cnt++;
            occurence.erase(right++);
        }
        return cnt;
    }
};
