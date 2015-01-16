struct Cmp {
  bool operator() (pair<int, int> i,pair<int, int> j) { return (i.first < j.first);}
} cmp;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<pair<int, int> > record;
        for (int i = 0;i < numbers.size();i++)
            record.push_back(make_pair(numbers[i], i + 1));
        sort(record.begin(), record.end(), cmp);
        int i = 0, j = record.size() - 1;
        while (i <= j)
            if (record[i].first + record[j].first < target)
                i++;
            else if (record[i].first + record[j].first > target)
                j--;
            else {
                vector<int> result;
                result.push_back(record[i].second);
                result.push_back(record[j].second);
                if (result[0] > result[1])
                    swap(result[0], result[1]);
                return result;
            }
    }
};
