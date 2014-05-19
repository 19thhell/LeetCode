class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1)
            return;
        int rev, i, j;
		for (i = num.size() - 2, rev = num.size() - 1;i >= 0;i--, rev--) {
            if (num[i] < num[rev]) {
                j = num.size();
                while (!(num[i] < num[--j]));
                swap(num[i], num[j]);
                reverse(num.begin() + i + 1, num.end());
				return;
            }
		}
		reverse(num.begin(), num.end());
    }
};
