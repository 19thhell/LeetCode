class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_map<string, vector<string> > words;
        vector<string> result;
        for (int i = 0;i < strs.size();i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            words[word].push_back(strs[i]);
        }
        for (auto const &pair : words)
            if ((pair.second).size() > 1)
                for (auto const &list : pair.second)
                    result.push_back(list);
        return result;
    }
};
