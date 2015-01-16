//KMP
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!haystack || !needle)
			return NULL;
        int m = strlen(haystack), n = strlen(needle), index = 0, cur = 0;
		vector<int> next(n);
        getNext(needle, next);
        while (index < m && cur < n) {
            if (cur == -1 || haystack[index] == needle[cur]) {
                index++;
                cur++;
            }
            else cur = next[cur];
        }
        if (cur >= n)
            return index - n;
        else return -1;
    }
private:
    void getNext(const char *str, vector<int> &next) {
        if (next.size() == 0)
            return;
        int n = next.size(), i = 0, j = -1;
        next[0] = -1;
        while (i < n - 1) {
            if (j == -1 || str[i] == str[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else j = next[j];
        }
    }
};
