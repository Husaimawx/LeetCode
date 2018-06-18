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
        if(node == NULL)
            return NULL;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
        deque<UndirectedGraphNode*> dq;
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;
        dq.push_back(node);
        
        while(!dq.empty())
        {
            node = dq.front();
            dq.pop_front();
            for(int i = 0;i<node->neighbors.size();i++)
            {
                if(mp.find(node->neighbors[i]) != mp.end())
                {
                    mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
                }
                else
                {
                    dq.push_back(node->neighbors[i]);
                    mp[node->neighbors[i]] = new UndirectedGraphNode(node->neighbors[i]->label);
                    mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
                }
            }
        }
        
        return copy;
    }
};