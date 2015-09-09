class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int head = 0, tail = nums.size() - 1, left, right, pivot;
        while (true) {
            left = head;
            right = tail;
            pivot = nums[left++];
            while (left <= right) {
                while (left <= right && nums[left] >= pivot)
                    left++;
                while (left <= right && nums[right] < pivot)
                    right--;
                if (left <= right) {
                    swap(nums[left], nums[right]);
                    left++;
                    right--;
                }
            }
            if (left - head == k)
                return pivot;
            else if (left - head > k) {
                head++;
                tail = left - 1;
            }
            else {
                k -= left - head;
                head = left;
            }
        }
    }
};
