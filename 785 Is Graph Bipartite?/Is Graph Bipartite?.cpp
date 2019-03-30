class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size() < 3)
            return true;
        int N = graph.size();
        unordered_map<int,int> M;
        for(int i = 0;i<N;i++) {
            M[i] = -1;
        }
        
        int count = 0;
        int from = 0;
        while(count != N) {
            for(;M[from] != -1;from++);
            vector<int> st;
            st.push_back(from);
            int flag = 0;
            M[from] = flag;
            count += 1;
            int f = 0;
            while(f != st.size()) {
                flag = 1-flag;
                int t = st.size();
                for(int i = f;i<t;i++) {
                    for(int j = 0;j<graph[st[i]].size();j++) {
                        if(M[graph[st[i]][j]] + flag == 1)
                            return false;
                        if(M[graph[st[i]][j]] == -1) {
                            M[graph[st[i]][j]] = flag;
                            st.push_back(graph[st[i]][j]);
                            count += 1;
                        }
                    }
                }
                f = t;
            }
        }
        return true;
    }
};