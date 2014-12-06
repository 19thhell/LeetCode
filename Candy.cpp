class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), left = 0, sum;
        vector<int> right(n, 0);
		for (int i = n - 2;i >= 0;i--) {
            if (ratings[i] > ratings[i + 1])
                right[i] = right[i + 1] + 1;
		}
		sum = right[0] + 1;
        for (int i = 1;i < n;i++) {
            if (ratings[i] > ratings[i - 1])
                left++;
            else left = 0;
            sum += max(left, right[i]) + 1;
        }
        return sum;
    }
};
