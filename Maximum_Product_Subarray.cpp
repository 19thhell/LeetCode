class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n == 0)
			return 0;
		int max_cur = A[0], min_cur = A[0], result = A[0];
		for (int i = 1;i < n;i++) {
		    int max_prev = max_cur;
		    max_cur = max(max(max_prev * A[i], A[i]), min_cur * A[i]);
		    min_cur = min(min(max_prev * A[i], A[i]), min_cur * A[i]);
		    result = max(result, max_cur);
		}
		return result;
	}
};
