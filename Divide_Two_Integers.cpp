class Solution {
public:
    int divide(int dividend, int divisor) {
		long long abs_dividend = (long long)dividend, abs_divisor = (long long)divisor;
		if (abs_dividend < 0)
			abs_dividend = -abs_dividend;
		if (abs_divisor < 0)
			abs_divisor = -abs_divisor;
        if (abs_dividend < abs_divisor)
            return 0;
		int sign = 0, result;
		if ((dividend >> 31) ^ (divisor >> 31))
            sign = 1;
		if (abs_divisor == 1)
			return sign ? (int)-abs_dividend : (int)abs_dividend;
		result = divide(abs_dividend, abs_divisor);
		return sign ? -result : result;
	}

	int divide(long long abs_dividend, long long abs_divisor) {
		if (abs_dividend < abs_divisor)
			return 0;
        int cnt = 1, rest = 0;
		long long divi = abs_divisor;
        while (abs_divisor + abs_divisor <= abs_dividend) {
            abs_divisor += abs_divisor;
            cnt += cnt;
        }
		if (abs_divisor != abs_dividend)
			rest = divide(abs_dividend - abs_divisor, divi);
		return cnt + rest;
    }
};
