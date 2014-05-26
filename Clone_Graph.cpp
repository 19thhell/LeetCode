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
        UndirectedGraphNode *origin, *replica;
        q.push(node);
        while (!q.empty()) {
            origin = q.front();
            q.pop();
            if (new_nodes.find(origin->label) == new_nodes.end()) {
                new_nodes[origin->label] = new UndirectedGraphNode(origin->label);
                for (int i = 0;i < origin->neighbors.size();i++)
                    q.push(origin->neighbors[i]);
            }
        }
        q.push(node);
        while (!q.empty()) {
            origin = q.front();
            q.pop();
            replica = new_nodes[origin->label];
            if (replica->neighbors.empty())
                for (int i = 0;i < origin->neighbors.size();i++) {
                    replica->neighbors.push_back(new_nodes[origin->neighbors[i]->label]);
                    q.push(origin->neighbors[i]);
                }
        }
        return new_nodes[node->label];
    }
};
