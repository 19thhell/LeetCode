class Solution {
public:
    int addDigits(int num) {
        if (num == 0) {
            return 0;
        }
        return num - (num - 1) / 9 * 9;
    }
};
