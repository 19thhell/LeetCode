class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int cnt = 0, c_max = 0;
        while(*s) {
            if (*s == ' ')
                cnt = 0;
            else {
                cnt++;
                c_max = cnt;
            }
            s++;
        }
        return c_max;
    }
};;
