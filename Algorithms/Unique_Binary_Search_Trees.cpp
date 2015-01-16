class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        numTrees(1, n);
    }
    int numTrees(int s, int t){
        if (s >= t)
            return 1;
        int result = 0;
        for (int i = s;i <= t;i++){
            result += numTrees(s, i - 1) * numTrees(i + 1, t);
        }
        return result;
    }
};
