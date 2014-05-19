class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        int sum = 0;
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        if (num.size() < 4)
            return result;
        sort(num.begin(), num.end());
        vector<int> tmp;
        for (n1 = 0;n1 < num.size() - 3;n1++) {
            if (n1 > 0 && num[n1] == num[n1 - 1])
                continue;
            for (n2 = n1 + 1;n2 < num.size() - 2;n2++) {
                if (n2 > n1 + 1 && num[n2] == num[n2 - 1])
                    continue;
                n3 = n2 + 1;
                n4 = num.size() - 1;
                while (n3 < n4) {
                    if (n3 > n2 + 1 && num[n3] == num[n3 - 1]) {
                        n3++;
                        continue;
                    }
                    if (n4 < num.size() - 1 && num[n4] == num[n4 + 1]) {
                        n4--;
                        continue;
                    }
                    sum = num[n1] + num[n2] + num[n3] + num[n4];
                    if (sum == target) {
                        tmp.push_back(num[n1]);
                        tmp.push_back(num[n2]);
                        tmp.push_back(num[n3]);
                        tmp.push_back(num[n4]);
                        result.push_back(tmp);
                        tmp.clear();
                        n3++;
                    }
                    else {
                        if (sum < target)
                            n3++;
                        else n4--;
                    }
                }
            }
        }
        return result;
    }
};
