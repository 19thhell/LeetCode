class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        if (num.size() < 4)
            return result;
        sort(num.begin(), num.end());
        int sum = 0, n[4];
        vector<int> solution(4);
        for (n[0] = 0;n[0] < num.size() - 3;n[0]++) {
            if (n[0] > 0 && num[n[0]] == num[n[0] - 1])
                continue;
            for (n[1] = n[0] + 1;n[1] < num.size() - 2;n[1]++) {
                if (n[1] > n[0] + 1 && num[n[1]] == num[n[1] - 1])
                    continue;
                n[2] = n[1] + 1;
                n[3] = num.size() - 1;
                while (n[2] < n[3]) {
                    if (n[2] > n[1] + 1 && num[n[2]] == num[n[2] - 1]) {
                        n[2]++;
                        continue;
                    }
                    if (n[3] < num.size() - 1 && num[n[3]] == num[n[3] + 1]) {
                        n[3]--;
                        continue;
                    }
                    sum = num[n[0]] + num[n[1]] + num[n[2]] + num[n[3]];
                    if (sum == target) {
                        for (int i = 0;i < 4;i++)
                            solution[i] = num[n[i]];
                        result.push_back(solution);
                        n[2]++;
                    }
                    else {
                        if (sum < target)
                            n[2]++;
                        else n[3]--;
                    }
                }
            }
        }
        return result;
    }
};
