class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        long long exp = 1;
        int reverse = 0, rec = x;
        do
            exp *= 10;
        while (x / exp);
        if (x / exp == 0)
            exp /= 10;
        while (exp) {
            reverse += (rec % 10) * exp;
			rec /= 10;
			exp /= 10;
        }
        return x == reverse;
    }
};
