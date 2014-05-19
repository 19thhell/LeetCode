class Solution {
public:
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (n == 0)
            return 1;
        if (n > 0)
            return quickpow(x, n);
        else return 1 / quickpow(x, -n);
    }

    double quickpow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1 || x == 1)
            return x;
        if (x == -1)
            if (n & 1)
                return -1;
            else return 1;
        double result = x;
        int times = (int)log(n);
        int remain = n - (1 << times);
        while (times--)
            result *= result;
        result *= pow(x, remain);
        return result;
    }
};
