// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n <= 2) {
            if (isBadVersion(1)) {
                return 1;
            } else {
                return 2;
            }
        }
        int lower = 1, upper = n, test = lower + (upper - lower) / 2;
        while (lower < upper) {
            if (isBadVersion(test)) {
                upper = test;
            } else {
                lower = test + 1;
            }
            test = lower + (upper - lower) / 2;
        }
        return lower;
    }
};
