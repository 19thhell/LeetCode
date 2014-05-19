class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> result(rowIndex + 1);
        int mid = rowIndex / 2;
        for (int i = 0;i <= mid;i++) {
            result[i] = result[rowIndex - i] = c(rowIndex, i);
        }
        return result;
    }

    int c(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        long long up = 1, down = 1;
        for (int i = 1;i <= n;i++) {
            long long a = m - n + i;
            up *= a;
            down *= i;
            long long dv = gcd(up, down);
            up /= dv;
            down /= dv;
        }
        return (int)(up / down);
    }

    long long gcd(long long m, long long n) {
        if (!(m % n))
            return n;
        else return gcd(n, m % n);
    }
};
