class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if (num.size() < 3)
            return result;
        int sum = 0;
        for (int i = 0; i < num.size() - 2; i++)
        {
            if (i > 0 && num[i] == num[i - 1])
                continue;
            int left = i + 1, right = num.size() - 1, target = -num[i];
            while (left < right)
            {
                sum = num[left] + num[right];
                if (sum < target)
                {
                    do
                    {
                        left++;
                    }
                    while (left < right && num[left] == num[left - 1]);
                }
                else if (sum > target)
                {
                    do
                    {
                        right--;
                    }
                    while (left < right && num[right] == num[right + 1]);
                }
                else
                {
                    vector<int> triplet{num[i], num[left], num[right]};
                    result.push_back(triplet);
                    while (left < right && num[left] == triplet[1])
                        left++;
                    while (left < right && num[right] == triplet[2])
                        right--;
                }
            }
        }
        return result;
    }
};
