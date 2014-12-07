class Solution {
public:
    int lengthOfLastWord(const char *s) {
        stringstream ss;
        ss << s;
        string last;
        while (ss >> last);
        return last.size();
    }
};
