class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return peak(num, 0, num.size() - 1);
    }
private:
    int peak(const vector<int> &num, const int left, const int right) {
        if (left > right)
            return -1;
        int mid = (left + right) / 2;
        if (isPeak(num, mid))
            return mid;
        else {
            int subleft = peak(num, left, mid - 1);
            if (subleft >= 0)
                return subleft;
            else return peak(num, mid + 1, right);
        }
    }
    
    inline bool isPeak(const vector<int> &num, const int index) {
        long long inf = -1LL << 32, left = (index == 0) ? inf : (long long)num[index - 1], right = (index == num.size() - 1) ? inf : (long long)num[index + 1], val = (long long)num[index];
		return val > left && val > right;
    }
};
