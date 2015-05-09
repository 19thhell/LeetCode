class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        int result = n - 2;
        vector<int> candidate(n, 1);
        for (int i = 2; i * i < n; i++) {
            if (candidate[i]) {
                for (int j = 2; i * j < n; j++) {
                    if (candidate[i * j]) {
                        candidate[i * j] = 0;
                        result--;
                    }
                }
            }
        }
        return result;
    }
};
