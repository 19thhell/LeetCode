class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<string, vector<string> > words;
        vector<string> result;
        string tmp;
        for (int i = 0;i < strs.size();i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            words[tmp].push_back(strs[i]);
        }
        for (map<string, vector<string> >::iterator p = words.begin();p != words.end();p++)
            if ((p->second).size() > 1)
                for (vector<string>::iterator q = (p->second).begin();q != (p->second).end();q++)
                    result.push_back(*q);
        return result;
    }
};

class Cmp {
public:
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
        return a.first < b.first;
    }
};

