class Solution {
vector<vector<int>> res;
int N;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size(); 
        vector<int> path(1,0);
        sub(graph, 0, path);
        return res;
    }
    
    void sub(vector<vector<int>>& graph, int now, vector<int>& path) {
        if(now == N-1) {
            res.push_back(path);
            return;
        }
        for(int i = 0;i<graph[now].size();i++) {
            path.push_back(graph[now][i]);
            sub(graph, path[path.size()-1], path);
            path.pop_back();
        }
        return;
    } 
};