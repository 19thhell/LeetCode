class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), sum = 0;
        vector<int> left(n, 0), right(n, 0);
		for (int i = 1, j = n - 2;i < n && j >= 0;i++, j--) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
            if (ratings[j] > ratings[j + 1])
                right[j] = right[j + 1] + 1;
		}
        for (int i = 0;i < n;i++)
            sum += max(left[i], right[i]) + 1;
        return sum;
    }
};
