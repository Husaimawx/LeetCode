class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edge) {
        vector<int> temp;
        vector<vector<int>> graph(N, temp);
        for(int i = 0;i<N-1;i++) {
            graph[edge[i][0]].push_back(edge[i][1]);
            graph[edge[i][1]].push_back(edge[i][0]);
        }
        
        vector<int> count(N,0);
        vector<int> res(N,0);
        dfs1(graph, 0, INT_MAX, count, res);
        dfs2(graph, 0, INT_MAX, count, res, N);
        return res;
    }
    
    void dfs1(vector<vector<int>>& graph, int root, int dad, vector<int>& count, vector<int>& res) {
        int c = 1;
        int r = 0;
        for(int i = 0;i<graph[root].size();i++) {
            if(graph[root][i] == dad)
                continue;
            dfs1(graph, graph[root][i], root, count, res);
            c += count[graph[root][i]];
            r += (count[graph[root][i]] + res[graph[root][i]]);
        }    
        count[root] = c;
        res[root] = r;
        return;
    }
    
    void dfs2(vector<vector<int>>& graph, int root, int dad, vector<int>& count, vector<int>& res, int N) {
        if(root != 0) {
            res[root] = res[dad] + (N-2*count[root]);
        }
        for(int i = 0;i<graph[root].size();i++) {
            if(graph[root][i] == dad)
                continue;
            dfs2(graph, graph[root][i], root, count, res, N);
        }
        return;
    }
};