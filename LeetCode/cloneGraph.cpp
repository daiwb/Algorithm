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
    map<int, UndirectedGraphNode*> vv;
    UndirectedGraphNode* doit(UndirectedGraphNode *v) {
        UndirectedGraphNode *res = new UndirectedGraphNode(v->label);
        vv[v->label] = res;
        for (int i = 0; i < v->neighbors.size(); ++i) {
            if (!vv[v->neighbors[i]->label]) res->neighbors.push_back(doit(v->neighbors[i]));
            else res->neighbors.push_back(vv[v->neighbors[i]->label]);
        }
        return res;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        vv.clear();
        return doit(node);
    }
};