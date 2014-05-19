//Newton's method
class Solution {
public:
    int sqrt(int x) {
        if (x == 0)
            return 0;
        double pre = 1, cur = 1;
        do {
            pre = cur;
            cur = x / (pre * 2) + pre / 2;
        }
        while (abs(cur - pre) > 1e-6);
        return int(cur);
    }
};
