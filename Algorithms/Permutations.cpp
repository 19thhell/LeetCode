//Solution 1: stl
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        }
        while (next_permutation(num.begin(), num.end()));
        return result;
    }
};

//Solution 2: recursive
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        if (!num.empty())
            permutation(result, num, 0);
        return result;
    }

    void permutation(vector<vector<int> > &result, vector<int> &num, int k) {
		if (k >= num.size())
            result.push_back(num);
            return;
        }
        for (int i = k;i < num.size();i++) {
            swap(num[k], num[i]);
            permutation(result, num, k + 1);
            swap(num[k], num[i]);
        }
    }
};
