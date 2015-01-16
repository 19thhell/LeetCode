class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1, cur;
    	while (left < right) {
    		cur = left + (right - left) / 2;
    		if (num[cur] <= num[right])
    			right = cur;
    		else left = cur + 1;
    	}
    	return num[left];
    }
};
