class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!(*s)) {
            if (!(*p)) {
                return true;
            }
            else if (*(p + 1) == '*') {
                return isMatch(s, p + 2);
            }
            else return false;
        }
        else if (!(*p)) {
            return false;
        }
        else if (*(p + 1) == '*') {
            if (*s != *p && *p != '.') {
                return isMatch(s, p + 2);
            }
            for (NULL;*p && *(p + 1) == '*';p += 2) {
                if (isMatch(s + 1, p)) {
                    return true;
                }
            }
            return isMatch(s, p);
        }
        else {
            if (*s == *p || *p == '.') {
                return isMatch(s + 1, p + 1);
            }
            else return false;
        }
    }
};
