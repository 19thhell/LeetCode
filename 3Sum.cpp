class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        int sum = 0;
        sort(num.begin(), num.end());
        if (num.size() < 3)
            return result;
        int n1 = 0, n2 = 0, n3 = 0;
        vector<int> tmp;
        for (n1 = 0;n1 < num.size() - 2;n1++) {
            if (n1 > 0 && num[n1] == num[n1 - 1])
                continue;
            n2 = n1 + 1;
            n3 = num.size() - 1;
            while (n2 < n3) {
                if(n2 > n1 + 1 && num[n2] == num[n2 - 1]){
                    n2++;
                    continue;
                }
                if(n3 < num.size() - 1 && num[n3] == num[n3 + 1]){
                    n3--;
                    continue;
                }
                sum = num[n2] + num[n3];
                if (sum == -num[n1]) {
                    tmp.push_back(num[n1]);
                    tmp.push_back(num[n2]);
                    tmp.push_back(num[n3]);
                    result.push_back(tmp);
                    tmp.clear();
                    n2++;
                }
                else {
                    if (sum < -num[n1])
                        n2++;
                    else n3--;
                }
            }
        }
        return result;
    }
};
