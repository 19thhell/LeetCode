class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result;
        int index = search(A, 0, n - 1, target);
        int rangel = index, ranger = index;
        if (index != -1) {
            int i = index, j = index;
            while (true) {
                i = search(A, 0, i - 1, target);
                if (i != -1)
                    rangel = i;
                else break;
            }

            while (true){
                j = search(A, j + 1, n - 1, target);
                if (j != -1)
                    ranger = j;
                else break;
            }
        }
        result.push_back(rangel);
        result.push_back(ranger);
        return result;
    }

    int search(int A[], int start, int end, int target) {
        int left = start, right = end, mid;
        if (start > end)
            return -1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
