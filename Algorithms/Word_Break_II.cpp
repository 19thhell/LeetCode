class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        if (s.size() == 0)
            return result;
        vector<string> sentence;
        vector<bool> can_break(s.size(), true);
        dfs(s, dict, 0, can_break, result, sentence);
        return result;
    }

    bool dfs(string &s, unordered_set<string> &dict, int index, vector<bool> &can_break, vector<string> &result, vector<string> &sentence) {
		if (index >= s.size()) {
		    string segment = sentence[0];
		    for (int i = 1;i < sentence.size();i++) {
		        segment += " ";
		        segment += sentence[i];
		    }
		    result.push_back(segment);
			return true;
		}
		if (!can_break[index])
			return false;
		string word;
		bool flag = false;
		for (int i = index;i < s.size();i++) {
			word += s[i];
			if (dict.find(word) != dict.end()) {
			    sentence.push_back(word);
			    if (dfs(s, dict, i + 1, can_break, result, sentence))
			        flag = true;
			    sentence.pop_back();
			}
		}
		can_break[index] = flag;
		return flag;
    }
};
