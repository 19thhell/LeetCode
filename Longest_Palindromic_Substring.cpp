//Manacher algorithm
class Solution {
public:
    string process(string s) {
        if (s.size() == 0)
            return "^$";
        string res = "^";
        for (int i = 0;i < s.size();i++)
            res += "#" + s.substr(i, 1);
        res += "#$";
        return res;
    }
    
    string longestPalindrome(string s) {
        string t = process(s);
        vector<int> p(t.size());
        int id = 0, maxl = 0;
        for (int i = 1;i < t.size() - 1;i++) {
            int j = 2 * id - i;
            p[i] = maxl > i ? min(maxl - i, p[j]) : 1;
            while (t[i + p[i]] == t[i - p[i]])
                p[i]++;
            if (i + p[i] > maxl) {
                id = i;
                maxl = i + p[i];
            }
        }
        maxl = 0, id = 0;
        for (int i = 1;i < t.size();i++)
            if (p[i] > maxl) {
                maxl = p[i];
                id = i;
            }
        return s.substr((id - maxl) / 2, maxl - 1);
    }
};
