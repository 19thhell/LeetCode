class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        if (numCourses < 2 || prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; i++)
                order.push_back(i);
            return order;
        }
        unordered_map<int, int> timeStamp;
        vector<vector<int>> adjList(numCourses);
        vector<int> starts;
        for (const auto& edge : prerequisites) {
            adjList[edge.second].push_back(edge.first);
        }
        vector<int> colors(numCourses, 0);
        for (int start = 0; start < numCourses; start++) {
            if (colors[start] == 2)
                continue;
            colors[start] = 1;
            int time = 0;
            bool noCycle = dfs(start, adjList, colors, order);
            if (!noCycle) {
                order.clear();
                return order;
            }
            colors[start] = 2;
            order.push_back(start);
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    bool dfs(int start, vector<vector<int>>& adjList, vector<int>& colors, vector<int> &order) {
        for (const auto next : adjList[start]) {
            if (colors[next] == 1) {
                return false;
            }
            else if (colors[next] == 2) {
                continue;
            }
            colors[next] = 1;
            bool noCycle = dfs(next, adjList, colors, order);
            if (!noCycle)
                return false;
            colors[next] = 2;
            order.push_back(next);
        }
        return true;
    }
};
