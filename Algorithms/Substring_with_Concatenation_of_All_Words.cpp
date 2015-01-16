class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if (S.size() == 0 || L.empty())
            return result;
        unordered_map<string, int> visit, count;
        vector<bool> accept(S.size(), true);
        for (int i = 0;i < L.size();i++)
            count[L[i]]++;
        int len = L[0].size(), total = L.size(), cnt;
        for (int i = 0;i <= (int)S.size() - len * total;i++) {
            if (!accept[i])
                continue;
            visit.clear();
            cnt = 0;
            for (int j = 0;j < total;j++) {
                string tmp = S.substr(i + j * len, len);
                if (count.find(tmp) == count.end()) {
                    for (int k = 0;k <= j;k++)
                        accept[i + k * len] = false;
                    break;
                }
                else if (count[tmp] < ++visit[tmp])
                    break;
                cnt++;
            }
            if (cnt >= total)
                result.push_back(i);
        }
        return result;
    }
};
