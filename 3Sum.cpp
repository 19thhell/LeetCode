class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if (num.size() < 3)
            return result;
        int sum = 0, n[3];
		vector<int> solution(3);
        for (n[0] = 0;n[0] < num.size() - 2;n[0]++) {
            if (n[0] > 0 && num[n[0]] == num[n[0] - 1])
                continue;
            n[1] = n[0] + 1;
            n[2] = num.size() - 1;
            while (n[1] < n[2]) {
                if(n[1] > n[0] + 1 && num[n[1]] == num[n[1] - 1]){
                    n[1]++;
                    continue;
                }
                if(n[2] < num.size() - 1 && num[n[2]] == num[n[2] + 1]){
                    n[2]--;
                    continue;
                }
                sum = num[n[1]] + num[n[2]];
                if (sum == -num[n[0]]) {
                    for (int i = 0;i < 3;i++)
                        solution[i] = num[n[i]];
                    result.push_back(solution);
                    n[1]++;
                }
                else {
                    if (sum < -num[n[0]])
                        n[1]++;
                    else n[2]--;
                }
            }
        }
        return result;
    }
};
