class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 2 || prerequisites.size() == 0)
            return true;
        vector<vector<int>> adjList(numCourses);
        vector<int> starts;
        for (const auto& edge : prerequisites) {
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> colors(numCourses, 0);
        for (int start = 0; start < numCourses; start++) {
            if (colors[start] == 2)
                continue;
            colors[start] = 1;
            bool noCycle = dfs(start, adjList, colors);
            if (!noCycle)
                return false;
            colors[start] = 2;
        }
        return true;
    }
private:
    bool dfs(int start, vector<vector<int>>& adjList, vector<int>& colors) {
        for (auto next : adjList[start]) {
            if (colors[next] == 1) {
                return false;
            }
            else if (colors[next] == 2) {
                continue;
            }
            colors[next] = 1;
            bool noCycle = dfs(next, adjList, colors);
            if (!noCycle)
                return false;
            colors[next] = 2;
        }
        return true;
    }
};
