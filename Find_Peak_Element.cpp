class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return peak(num, 0, num.size() - 1);
    }
private:
    int peak(const vector<int> &num, int left, int right) {
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
    
    bool isPeak(const vector<int> &num, int index) {
        if (index == 0 && index == num.size() - 1)
            return true;
        else if (index == 0 && index < num.size() - 1 && num[index] > num[index + 1])
            return true;
        else if (index > 0 && index == num.size() - 1 && num[index] > num[index - 1])
            return true;
        else if (index > 0 && index < num.size() - 1 && num[index] > num[index - 1] && num[index] > num[index + 1])
            return true;
        else return false;
    }
};
