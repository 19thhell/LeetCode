class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string word;
        ss >> s;
        if (ss.fail()) {
            s.clear();
            return;
        }
        while (ss >> word) {
            s = word + " " + s;
        }
    }
};
