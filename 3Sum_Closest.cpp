class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int result = 0x7fffffff, sum = 0, n1, n2, n3;
        sort(num.begin(), num.end());
        for (n1 = 0;n1 < num.size() - 2;n1++) {
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
                        n2++;
                    else n3--;
                }
            }
        }
        return result;
    }
};
