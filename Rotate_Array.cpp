class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        if (!k)
            return;
        int left = 0, mid = n - k - 1, right = n - 1;
        for (int i = left, j = mid; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
        for (int i = mid + 1, j = right; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
        for (int i = left, j = right; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
    }
};
