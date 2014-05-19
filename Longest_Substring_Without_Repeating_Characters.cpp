class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pos[256];
        for (int i = 0;i < 256;i++)
            pos[i] = -1;
        int cur_start = 0, cur_len = 0, max_len = 0;;
        for (int i = 0;i < s.size();i++) {
            if (pos[s[i]] >= cur_start)
                cur_start = pos[s[i]] + 1;
            pos[s[i]] = i;
            cur_len = i - cur_start + 1;
            if (cur_len > max_len)
                max_len = cur_len;
        }
        return max_len;
    }
};
