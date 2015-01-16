class Solution {
public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int p = m + n - 2, q = (m < n)?m - 1:n - 1;
        long long up = 1, down = 1;
        for (int i = 1;i <= q;i++) {
            int a = p - q + i;
            int dv = gcd(a, i);
            up *= a / dv;
            down *= i / dv;
        }
        return (int)(up / down);
    }

    int gcd(int m, int n) {
        if (!(m % n))
            return n;
        else return gcd(n, m % n);
    }
};
