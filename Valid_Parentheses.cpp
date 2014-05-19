class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<char> p;
        for (int i = 0;i < s.size();i++) {
            if (isLeft(s[i]))
                p.push(s[i]);
            else {
                if (p.empty())
                    return false;
                if (match(p.top(), s[i]))
                    p.pop();
                else return false;
            }
        }
        return p.empty();
    }

    inline bool match(char a, char b) {
        return (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}');
    }

    inline bool isLeft(char c) {
        return (c == '(' || c == '[' || c == '{');
    }
};
