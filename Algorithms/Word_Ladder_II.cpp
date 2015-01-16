class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > prev;
        vector<string> parent, &path = parent;
        for (unordered_set<string>::const_iterator p = dict.begin();p != dict.end();p++)
            prev[*p] = parent;
        vector<unordered_set<string> > q(2);
        int cur = 0, pre = 1;
        dict.insert(start);
        dict.insert(end);
        q[cur].insert(start);
        while (true) {
            pre = !pre;
            cur = !cur;
            for (unordered_set<string>::const_iterator p = q[pre].begin();p != q[pre].end();p++)
                dict.erase(*p);
            q[cur].clear();
            for (unordered_set<string>::const_iterator p = q[pre].begin();p != q[pre].end();p++) {
                string tmp = *p;
                for (int i = 0;i < tmp.size();i++) {
                    int stop = tmp[i] - 'a';
                    for (int j = (stop + 1) % 26;j != stop;j = (j + 1) % 26) {
                        tmp[i] = j + 'a';
                        if (dict.find(tmp) != dict.end()) {
                            q[cur].insert(tmp);
                            prev[tmp].push_back(*p);
                        }
                    }
                    tmp[i] = stop + 'a';
                }
            }
            if (q[cur].empty())
                return result;
            if (q[cur].count(end))
                break;
        }
        getPath(result, path, prev, end);
        return result;
    }

    void getPath(vector<vector<string> > &result, vector<string> &path, unordered_map<string, vector<string> > &prev, string word) {
        if (prev[word].empty()) {
            path.push_back(word);
            vector<string> cur = path;
            reverse(cur.begin(), cur.end());
            result.push_back(cur);
            path.pop_back();
            return;
        }
        path.push_back(word);
        for (int i = 0;i < prev[word].size();i++)
            getPath(result, path, prev, prev[word][i]);
        path.pop_back();
    }
};
