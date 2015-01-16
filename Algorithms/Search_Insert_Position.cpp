class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int left = 0, right = n - 1, mid;
        while (left <= right){
            mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};
