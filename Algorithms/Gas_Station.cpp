class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, fuel = 0, n = gas.size();
        for (int i = 0;i < n * 2 - 1;i++) {
            fuel += gas[i % n];
            if (fuel < cost[i % n]) {
                start = (i + 1) % n;
                fuel = 0;
                continue;
            }
            else fuel -= cost[i % n];
            if (start == (i + 1) % n)
                return start;
        }
        return -1;
    }
};
