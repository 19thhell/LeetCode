class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt_s[26] = {0};
        int cnt_t[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++cnt_s[s[i] - 'a'];
            ++cnt_t[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt_s[i] != cnt_t[i]) {
                return false;
            }
        }
        return true;
    }
};
