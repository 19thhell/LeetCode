class Solution {
public:
    int atoi(const char *str) {
        int i = 0, sign = 1, len = strlen(str);
        static const int max_num = 0x7fffffff, min_num = 0x80000000;
        long long result = 0;
        while (str[i] == ' ')
            i++;
        if (i >= len)
            return 0;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        else if (!isnum(str[i]))
            return 0;
        while (i < len) {
            if (!isnum(str[i]))
                return (int)result;
            result = result * 10 + sign * (str[i] - '0');
            i++;
            if (result >= max_num)
                return max_num;
            else if (result <= min_num)
                return min_num;
        }
        return (int)result;
    }

    int isnum(char c) {
        return (c >= '0' && c <= '9');
    }
};
