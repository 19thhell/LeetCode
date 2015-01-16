class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0)
            return false;
        if (dict.find(s) != dict.end())
            return true;
        vector<bool> can_break(s.size(), true);
        return dfs(s, dict, 0, can_break);
    }

    bool dfs(string &s, unordered_set<string> &dict, int index, vector<bool> &can_break) {
        if (!can_break[index])
			return false;
		if (index >= s.size())
			return true;
		string word;
		for (int i = index;i < s.size();i++) {
			word += s[i];
			if (dict.find(word) != dict.end() && dfs(s, dict, i + 1, can_break))
				return true;
		}
		can_break[index] = false;
		return false;
    }
};
