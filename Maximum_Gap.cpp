class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;
        vector<vector<int> > buckets(10, vector<int>());
        queue<int> result;
        int max_diff = 0, prev = num[0], cur;
        bool sorted = true;
        for (int n : num) {
            if (prev > n)
                sorted = false;
            prev = n;
            result.push(n);
        }
        if (!sorted) {
            for (int i = 0;i < 10;i++) {
                for (int j = 0;j < 10;j++)
                    buckets[j].clear();
                prev = num[0];
                while (!result.empty()) {
                    int n = result.front();
                    result.pop();
                    buckets[getDigit(n, i)].push_back(n);
                    prev = min(prev, n);
                }
                sorted = true;
                for (auto p = buckets.begin();p != buckets.end();p++) {
                    for (int n : *p) {
                        if (prev > n)
                            sorted = false;
                        prev = n;
                        result.push(n);
                    }
                }
                if (sorted)
                    break;
            }
        }
        prev = result.front();
        result.pop();
        while (!result.empty()) {
            cur = result.front();
            result.pop();
            max_diff = max(max_diff, cur - prev);
            prev = cur;
        }
        return max_diff;
    }
private:
    int getDigit(int num, int pos) {
        for (int i = 0;i < pos;i++) {
            num /= 10;
        }
        return num % 10;
    }
};
