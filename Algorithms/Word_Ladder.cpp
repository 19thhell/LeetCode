class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start.size() != end.size() || dict.empty())
            return 0;
        int len = 1, cur = 0;
        queue<string> q[2];
        q[cur].push(start);
        while (!q[cur].empty()){
            while (!q[cur].empty()) {
                string s = q[cur].front();
                q[cur].pop();
                for (int i = 0;i < s.size();i++) {
                    char tmp = s[i];
                    for (int c = 'a';c <= 'z';c++) {
                        if (tmp == c) {
                            dict.erase(s);
                            continue;
                        }
                        s[i] = c;
                        if (s == end)
                            return len + 1;
                        if (dict.find(s.c_str()) != dict.end()) {
                            if (s == end)
                                return len + 1;
                            else {
                                q[cur ^ 1].push(s);
                                dict.erase(s);
                            }
                        }
                    }
                    s[i] = tmp;
                }
            }
            cur ^= 1;
            len++;
        }
        return 0;
    }
};
