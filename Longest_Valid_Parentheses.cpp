class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
		int lastleft = 0, result = 0;
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '(')
				stk.push(i);
			else {
				if (!stk.empty()) {
					stk.pop();
					if (!stk.empty())
						result = max(result, i - stk.top());
					else result = max(result, i - lastleft + 1);
				}
				else lastleft = i + 1;
			}
		}
		return result;
    }
};
