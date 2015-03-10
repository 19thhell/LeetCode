class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0x7ffffff;
        int sum = 0;
        sort(num.begin(), num.end());
        int n1, n2, n3;
        for (n1 = 0;n1 < num.size() - 2;n1++) {
            if (n1 > 0 && num[n1] == num[n1 - 1])
                continue;
            n2 = n1 + 1;
            n3 = num.size() - 1;
            while (n2 < n3) {
                sum = num[n1] + num[n2] + num[n3];
                if (sum == target)
                    return sum;
                else  {
                    if (abs(result - target) > abs(sum - target))
                        result = sum;
                    if (sum < target)
                        do
                        {
                            n2++;
                        }
                        while (num[n2] == num[n2 - 1]);
                    else
                        do
                        {
                            n3--;
                        }
                        while (num[n3] == num[n3 + 1]);
                }
            }
        }
        return result;
    }
};
