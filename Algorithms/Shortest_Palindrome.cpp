class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty())
            return s;
        int center = 0, radius = 0;
        string t = "^#";
        for (char ch : s) {
            t += ch;
            t += "#";
        }
        t += "$";
        vector<int> palin_len(t.size(), 0);
        int max_len = 0, index = 0;
        for (int i = 1; i < t.size() - 1; i++) {
            int i_symmetric = 2 * center - i;
            if (radius > i_symmetric)
                palin_len[i] = min(palin_len[i_symmetric], radius - i);
            while (t[i - 1 - palin_len[i]] == t[i + 1 + palin_len[i]])
                palin_len[i]++;
            if (i + palin_len[i] > radius) {
                center = i;
                radius = i + palin_len[i];
            }
            if (palin_len[i] > max_len && palin_len[i] == i - 1) {
                max_len = palin_len[i];
                index = i;
            }
        }
        string seg = s.substr((index + max_len - 1) / 2);
        reverse(seg.begin(), seg.end());
        return seg + s;
    }
};
