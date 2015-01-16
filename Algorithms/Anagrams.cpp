class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<string, vector<string> > words;
        vector<string> result;
        for (int i = 0;i < strs.size();i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            words[word].push_back(strs[i]);
        }
        for (auto p = words.begin();p != words.end();p++)
            if ((p->second).size() > 1)
                for (auto q = (p->second).begin();q != (p->second).end();q++)
                    result.push_back(*q);
        return result;
    }
};
