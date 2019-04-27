class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        if(graph[0].size() == 0)
            return 0;
        
        map<pair<int,int>, int> M;
        vector<pair<int,int>> V;
        for(int i = 0;i<N;i++) {
            M[pair<int,int>(1<<i,i)] = 0;
            V.push_back(pair<int,int>(1<<i,i));
        }
        
        int from = 0;
        while(1) {
            int to = V.size();
            for(int i = from;i<to;i++) {
                int store = V[i].first;
                int now = V[i].second;
                for(int j = 0;j<graph[now].size();j++) {
                    int new_store = store | 1<<graph[now][j];
                    int new_head = graph[now][j];
                    if(M.count(pair<int,int>(new_store, new_head)) == 0) {
                        M[pair<int,int>(new_store, new_head)] = M[V[i]]+1;
                        V.push_back(pair<int,int>(new_store, new_head));
                        if(new_store+1 == (1<<N))
                            return M[V[i]]+1;
                    }
                }
            }
            from = to;
        }
    };
};