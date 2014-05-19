class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m - 1, mid, index;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                left = mid + 1;
            else right = mid - 1;
        }
        if (left == 0)
            return false;
        index = left - 1;
        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (matrix[index][mid] == target)
                return true;
            else if (matrix[index][mid] < target)
                left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
