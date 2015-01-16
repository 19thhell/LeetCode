class Solution {
public:
    bool search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return search(A, 0, n - 1, target);
    }

    bool search(int A[], int left, int right, int target) {
        if (left > right)
            return false;
        int mid = (left + right) / 2;
        if (A[mid] == target)
            return true;
        if (A[left] < A[mid]) {
            if (target < A[left] || target > A[mid])
                return search(A, mid + 1, right, target);
            else return search(A, left, mid - 1, target);
        }
        else if (A[left] > A[mid]) {
            if (target < A[mid] || target > A[right])
                return search(A, left, mid - 1, target);
            else return search(A, mid + 1, right, target);
        }
        else return search(A, left + 1, right, target);
    }
};
