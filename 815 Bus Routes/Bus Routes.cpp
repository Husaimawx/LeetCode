class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        if(S == T)
            return 0;
        
        map<int, vector<int>> M;
        for(int i = 0;i<routes.size();i++) {
            for(int j = 0;j<routes[i].size();j++) {
                if(M.count(routes[i][j]) == 0) {
                    M[routes[i][j]] = vector<int>(1, i);
                } else {
                    M[routes[i][j]].push_back(i);
                }
            }
        }
        
        //cout << M[1][0] << M[2][0] << M[3][0] << M[6][0] << M[7][0] << M[7][1];
        
        vector<int> rch(1,S);
        map<int,int> mrch;
        map<int,int> done;
        mrch[S] = 1;
        int from = 0;
        int res = 1;
        while(from != rch.size()) {
            int to = rch.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<M[rch[i]].size();j++) {
                    //cout << M[rch[i]][j] << endl;
                    if(done.count(M[rch[i]][j]) == 1)
                        continue;
                    for(int k = 0;k<routes[M[rch[i]][j]].size();k++) {
                        if(routes[M[rch[i]][j]][k] == T)
                            return res;
                        if(mrch.count(routes[M[rch[i]][j]][k]) == 0) {
                            rch.push_back(routes[M[rch[i]][j]][k]);
                            mrch[routes[M[rch[i]][j]][k]] = 1;
                        }
                    }
                    done[M[rch[i]][j]] = 1;
                }
            }
            from = to;
            res += 1;
        }
        return -1;
    }
};