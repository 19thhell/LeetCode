class Solution {
public:
    bool isPalindrome(string &s, int head, int tail) {
        while (head < tail) {
            if (s[head] != s[tail])
                return false;
            head++;
            tail--;
        }
        return true;
    }
    
    void dfs(vector<vector<string>> &result, vector<string> &partition, string &s, int head) {
        if (head == s.size()) {
            result.push_back(partition);
            return;
        }
        for (int i = head;i < s.size();i++) {
            if (isPalindrome(s, head, i)) {
                partition.push_back(s.substr(head, i - head + 1));
                dfs(result, partition, s, i + 1);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        dfs(result, partition, s, 0);
        return result;
    }
};
