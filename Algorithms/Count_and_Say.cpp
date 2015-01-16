class Solution {
public:
    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string s = "1";
        while (--n)
            s = countAndSay(s);
        return s;
    }
private:
    string countAndSay(string &s) {
        char key = s[0];
        int cnt = 0;
        string nexts;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == key)
                cnt++;
            else {
                nexts.append(1, (char)(cnt + '0'));
                nexts.append(1, key);
                cnt = 1;
                key = s[i];
            }
        }
        nexts.append(1, (char)(cnt + '0'));
        nexts.append(1, key);
        return nexts;
    }
};
