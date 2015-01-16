class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;
        int i = 0, j = s.size() - 1, n = j;
        while (i < j) {
            while (i <= n && !(isAlpha(s[i]) || isNumeric(s[i])))
                i++;
            while (j >= 0 && !(isAlpha(s[j]) || isNumeric(s[j])))
                j--;
            if (i > n || j < 0)
                return true;
            if (equal(s[i++], s[j--]))
                continue;
            return false;
        }
        return true;
    }

    inline bool isAlpha(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

	inline bool isNumeric(char c) {
		return c >= '0' && c <= '9';
	}

    inline bool equal (char a, char b) {
        return a == b || abs(a - b) == 32 && isAlpha(a) && isAlpha(b);
    }
};
