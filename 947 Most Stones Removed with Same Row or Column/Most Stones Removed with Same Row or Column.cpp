class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        map<int,int> M;
        vector<map<int,int>> g;
        for(int i = 0;i<stones.size();i++) {
            if(M.count(stones[i][0]) == 0) {
                int n = M.size();
                M[stones[i][0]] = n;
                map<int,int> temp;
                g.push_back(temp);
            }
            g[M[stones[i][0]]][stones[i][1]] = 1;
        }
        
        vector<vector<int>> v;
        v.resize(g.size());
        for(int i = 0;i<g.size();i++) {
            for(int j = i+1;j<g.size();j++) {
                for(auto iter = g[i].begin();iter != g[i].end();iter++) {
                    if(g[j].count(iter->first) != 0) {
                        v[i].push_back(j);
                        v[j].push_back(i);
                        break;
                    }
                }
            }
        }
        
        int island = 0;
        int start = 0;
        map<int,int> M2;
        while(1) {
            island += 1;
            vector<int> v2;
            v2.push_back(start);
            int from = 0;
            while(from != v2.size()) {
                int to = v2.size();
                for(int i = from;i<to;i++) {
                    for(int j = 0;j<v[v2[i]].size();j++) {
                        if(M2.count(v[v2[i]][j]) == 0) {
                            M2[v[v2[i]][j]] = 1;
                            v2.push_back(v[v2[i]][j]);
                        }
                    }
                }
                from = to;
            }
            while(1) {
                start += 1;
                if(start == v.size())
                    return stones.size()-island;
                if(M2.count(start) == 0)
                    break;
            }
        }
        return -1;
    }
};