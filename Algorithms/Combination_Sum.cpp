class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > result;
        vector<int> sub;
        sort(candidates.begin(), candidates.end());
        generate(result, candidates, sub, 0, target);
        return result;
    }
private:
    void generate(vector<vector<int> > &result, vector<int> &cand, vector<int> &sub, int head, int target) {
        for (int i = head;i < cand.size();i++) {
            if (i != head && cand[i] == cand[i - 1])
                continue;
            if (cand[i] > target)
                return;
            else if (cand[i] == target) {
                sub.push_back(cand[i]);
                result.push_back(sub);
                sub.pop_back();
                return;
            }
            else {
                sub.push_back(cand[i]);
                generate(result, cand, sub, i, target - cand[i]);
                sub.pop_back();
            }
        }
    }
};
