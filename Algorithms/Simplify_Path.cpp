class Solution {
public:
    string simplifyPath(string path) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<string> paths;
        int i = 0, j = 0,prev = 0, cur = 0;
        string result = "", relative, tmp;
        while (i < path.size()) {
            tmp = "";
            while (i < path.size() && path[i] != '/') {
                tmp += path[i];
                i++;
            }
            if (tmp != "") {
                if (tmp == ".")
                    continue;
                else if (tmp == "..") {
                    if (!paths.empty())
                       paths.pop();
                }
                else paths.push(tmp);
            }
            i++;
        }
        while (!paths.empty()) {
            relative = paths.top();
            paths.pop();
            result = "/" + relative + result;
        }
        if (result == "")
           result = "/";
        return result;
    }
};
