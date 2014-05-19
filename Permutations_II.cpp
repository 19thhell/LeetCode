class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if (!num.empty())
            permutation(result, num, 0, num.size() - 1);
        return result;
    }

    void permutation(vector<vector<int> > &result, vector<int> &num, int beg, int end) {
        if (beg >= end) {
            result.push_back(num);
            return;
        }
        set<int> visit;
        for (int i = beg;i <= end;i++) {
            if (visit.find(num[i]) == visit.end())
                visit.insert(num[i]);
            else continue;
            swap(num[beg], num[i]);
            permutation(result, num, beg + 1, end);
            swap(num[beg], num[i]);
        }
    }
};
