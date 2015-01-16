class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *pp = nullptr, *sp = nullptr;
        while (*s) {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            }
            else if (*p == '*') {
                pp = p++;
                sp = s;
            }
            else if (pp) {
                p = pp + 1;
                s = ++sp;
            }
            else return false;
        }
        while (*p == '*') {
            p++;
        }
        return !(*p);
    }
};
