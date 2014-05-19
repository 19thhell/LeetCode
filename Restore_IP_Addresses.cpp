class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<int> pos(4);
        restore(result, pos, s, 0, 0);
        return result;
    }

    void restore(vector<string> &result, vector<int> &pos, string s, int start, int session) {
        if (session == 4) {
            if (start >= s.size()) {
                int begin = 0;
                string addr;
                for (int i = 0;i < 4;i++) {
                    string ip(s, begin, pos[i] - begin + 1);
                    begin = pos[i] + 1;
                    addr += i == 0 ? ip : "." + ip;
                }
                result.push_back(addr);
            }
            return;
        }
        for (int i = start;i < s.size();i++) {
            if (valid(s, start, i)) {
                pos[session] = i;
                restore(result, pos, s, i + 1, session + 1);
            }
        }
    }

    bool valid(string s, int start, int end) {
        string ip(s, start, end - start + 1);
        if (ip.size() == 1)
            return "0" <= ip && ip <= "9";
        else if (ip.size() == 2)
            return "10" <= ip && ip <= "99";
        else if (ip.size() == 3)
            return "100" <= ip && ip <= "255";
        else return false;
    }
};
