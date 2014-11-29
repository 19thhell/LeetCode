//Elegant way
class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;
        stringstream ss;
        string word;
        stack<string> stk;
        ss << s;
        while (ss >> word) {
            stk.push(word);
        }
        s = "";
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
            if (!stk.empty())
                s += " ";
        }
    }
};
//Clunky
class Solution {
public:
    void reverseWords(string &s) {
        if (s.size() == 0)
            return;
        int cnt = s.size() - 1;
        string word, result;
        while (true) {
            while (cnt >= 0 && s[cnt] == ' ')
                cnt--;
            while (cnt >= 0 && s[cnt] != ' ')
                word += s[cnt--];
			if (word == "")
				break;
            if (result.size() > 0)
                result += ' ';
            for (int i = word.size() - 1;i >= 0;i--)
				result += word[i];
            word = "";
        }
        s = result;
    }
};
