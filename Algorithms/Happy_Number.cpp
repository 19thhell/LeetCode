class Solution {
public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        while (n != 58 && n != 85) {
            int next = 0;
            while (n) {
                int last = n % 10;
                next += last * last;
                n /= 10;
            }
            return isHappy(next);
        }
        return false;
    }
};
