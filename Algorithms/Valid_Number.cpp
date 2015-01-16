class Solution {
public:
    bool isNumber(const char *s) {
        bool exp = false, dot = false, space = false, first = false, second = false;
        if (!s)
            return false;
        while (*s == ' ')
            s++;
        if (*s == '+' || *s == '-')
            s++;
        while (*s != '\0') {
            if (*s == '.') {
                if (exp || dot || space)
                    return false;
                else dot = true;
            }
            else if (*s == 'e' || *s == 'E') {
                if (exp || space)
                    return false;
                else exp = true;
            }
            else if (*s == '+' || *s == '-') {
                if (!exp || space || *(s - 1) != 'e' && *(s - 1) != 'E')
                    return false;
            }
            else if ('0' <= *s && *s <= '9') {
                if (space)
                    return false;
                if (!exp)
                    first = true;
                else second = true;
            }
            else if (*s == ' ')
                space = true;
            else return false;
            s++;
        }
        if (!first)
            return false;
        else if (exp && !second)
            return false;
        return true;
    }
};
