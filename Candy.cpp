class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), sum = 0;
        vector<int> left(n, 1), right(n, 1);
		for (int i = 1;i < n;i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
            if (ratings[n - i - 1] > ratings[n - i])
                right[n - i - 1] = right[n - i] + 1;
		}
        for (int i = 0;i < n;i++)
            sum += max(left[i], right[i]);
        return sum;
    }
};
