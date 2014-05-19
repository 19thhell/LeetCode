class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else {
            int result[2] = {1, 2};
            int index = 0;
            int step = 3;
            while (step <= n){
                result[index] = result[0] + result[1];
                index ^= 1;
                step++;
            }
            return result[index ^ 1];
        }
    }
};
