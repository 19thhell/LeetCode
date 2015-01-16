class Solution {
public:
    int findMin(vector<int> &num, int left, int right) {
        if (left > right)
            return 0x7fffffff;
        else if (left == right)
            return num[left];
    	int cur = left + (right - left) / 2;
    	if (num[cur] < num[right])
    		return findMin(num, left, cur);
    	else if (num[cur] > num[right])
    		return findMin(num, cur + 1, right);
    	else
    		return min(findMin(num, left, cur - 1), findMin(num, cur + 1, right));
    }

    int findMin(vector<int> &num) {
    	return findMin(num, 0, num.size() - 1);
    }
};
