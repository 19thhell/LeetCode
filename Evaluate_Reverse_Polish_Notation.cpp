class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.empty())
            return 0;
        stack<int> stk;
        for (int i = 0;i < tokens.size();i++) {
            if (!isOperator(tokens[i])) {
                stk.push(toInt(tokens[i]));
                continue;
            }
            int m = stk.top();
            stk.pop();
            int n = stk.top();
            stk.pop();
            if (tokens[i] == "+")
                stk.push(n + m);
            else if (tokens[i] == "-")
                stk.push(n - m);
            else if (tokens[i] == "*")
                stk.push(n * m);
            else if (tokens[i] == "/")
                stk.push(n / m);
        }
        return stk.top();
    }

    inline bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int toInt(string s) {
        int sign = 1, cnt = 0, result = 0;
        if (s[0] == '-') {
            sign = -1;
            cnt = 1;
        }
        for (int i = cnt;i < s.size();i++) {
            result *= 10;
            result += s[i] - '0';
        }
        return sign * result;
    }
};
