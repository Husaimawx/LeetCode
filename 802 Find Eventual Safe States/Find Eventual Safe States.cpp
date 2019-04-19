class Solution {
map<int,int> done;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {  
        
        vector<int> res;
        if(graph.size() == 0)
            return res;
        
        int from = 0;
        while(done.size() != graph.size()) {
            map<int,int> path;
            while(done.count(from) == 1)
                from += 1;
            path[from] = 1;
            DFS(graph, path, from);    
        }
        for(int i = 0;i<graph.size();i++) {
            if(done[i] == 1)
                res.push_back(i);
        }
        return res;
    }
    
    void DFS(vector<vector<int>>& graph, map<int,int>& path, int from) {
        for(int i = 0;i<graph[from].size();i++) {
            int chosen = graph[from][i];
            if(done.count(chosen) > 0) {
                if(done[chosen] == 0)
                    done[from] = 0;
            } else if(path.count(chosen) > 0) {
                done[chosen] = 0;
                done[from] = 0;
            } else {
                path[chosen] = 1;
                DFS(graph, path, chosen);
                path.erase(chosen);
                if(done[chosen] == 0)
                    done[from] = 0;
            }
        }
        if(done.count(from) == 0)
            done[from] = 1;
        return;
    }
};