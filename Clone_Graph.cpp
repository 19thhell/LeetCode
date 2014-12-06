/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
        unordered_map<int, UndirectedGraphNode *> new_nodes;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        UndirectedGraphNode *origin, *replica;
        while (!q.empty()) {
            origin = q.front();
            q.pop();
            if (new_nodes.find(origin->label) == new_nodes.end()) {
                new_nodes[origin->label] = new UndirectedGraphNode(origin->label);
                for (auto adj : origin->neighbors)
                    q.push(adj);
            }
        }
        q.push(node);
        while (!q.empty()) {
            origin = q.front();
            q.pop();
            replica = new_nodes[origin->label];
            if (replica->neighbors.empty())
                for (auto adj : origin->neighbors) {
                    replica->neighbors.push_back(new_nodes[adj->label]);
                    q.push(adj);
                }
        }
        return new_nodes[node->label];
    }
};
