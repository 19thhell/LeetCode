class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() == 0)
            return true;
        unordered_map<char, char> key2val, val2key;
        for (int i = 0; i < s.size(); i++) {
            if (key2val.count(s[i]) == 0 && val2key.count(t[i]) == 0) {
                key2val[s[i]] = t[i];
                val2key[t[i]] = s[i];
            }
            else if (t[i] != key2val[s[i]] || s[i] != val2key[t[i]]) {
                return false;
            }
        }
        return true;
    }
};
