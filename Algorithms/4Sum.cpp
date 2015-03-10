class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        if (num.size() < 4)
            return result;
        sort(num.begin(), num.end());
        int sum = 0;
        for (int i = 0; i < num.size() - 3; i++)
        {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int target3 = target - num[i];
            for (int j = i + 1; j < num.size() - 2; j++)
            {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                int target2 = target3 - num[j], left = j + 1, right = num.size() - 1;
                while (left < right)
                {
                    sum = num[left] + num[right];
                    if (sum < target2)
                    {
                        do
                        {
                            left++;
                        }
                        while (left < right && num[left] == num[left - 1]);
                    }
                    else if (sum > target2)
                    {
                        do
                        {
                            right--;
                        }
                        while (left < right && num[right] == num[right + 1]);
                    }
                    else
                    {
                        vector<int> quadraple{num[i], num[j], num[left], num[right]};
                        result.push_back(quadraple);
                        while (left < right && num[left] == quadraple[2])
                            left++;
                        while (left < right && num[right] == quadraple[3])
                            right--;
                    }
                }
            }
        }
        return result;
    }
};
