class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> layer(n,0);
        int layernow = 1;
        int count = 0;
        while(1)
        {
            vector<int> node_num(n,0);
            for(int i = 0;i<edges.size();i++)
            {
                if(layer[edges[i].first] == 0 && layer[edges[i].second] == 0)
                { 
                    node_num[edges[i].first]++;
                    node_num[edges[i].second]++;
                }
            }
            for(int i = 0;i<n;i++)
            {
                if(node_num[i] == 1)
                {
                    layer[i] = layernow;
                    count++;
                }
            }
            if(count == n)
            {
                vector<int> res;
                for(int i = 0;i<n;i++)
                {
                    if(layer[i] == layernow)
                        res.push_back(i);
                }
                return res;
            }
            else if(count == n-1)
            {
                vector<int> res;
                for(int i = 0;i<n;i++)
                {
                    if(layer[i] == 0)
                        res.push_back(i);
                }
                return res;                
            }
            
            layernow++;
        }
    }
};