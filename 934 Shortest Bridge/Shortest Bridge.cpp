class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int x,y;
        for(x = 0;x<A.size();x++) {
            for(y = 0;y<A.size();y++) {
                if(A[x][y] == 1)
                    break;
            }
            if(y != A.size())
                break;
        }
        
        vector<int> dir{-1,0,1,0,-1};
        unordered_map<int,int> M;
        M[100*x+y] = 1;
        vector<int> v(1,100*x+y);
        int from = 0;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                for(int t = 0;t<4;t++) {
                    int nx = v[i]/100+dir[t];
                    int ny = v[i]%100+dir[t+1];
                    if(nx >= 0 && ny >=0 && nx < A.size() && ny < A.size() && M.count(100*nx+ny) == 0 && A[nx][ny] == 1) {
                        M[100*nx+ny] = 1;
                        v.push_back(100*nx+ny);
                    }
                }
            }
            from = to;
        }
        
        int res = 0;
        from = 0;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                for(int t = 0;t<4;t++) {
                    int nx = v[i]/100+dir[t];
                    int ny = v[i]%100+dir[t+1];
                    if(nx >= 0 && ny >=0 && nx < A.size() && ny < A.size() && M.count(100*nx+ny) == 0) {
                        if(A[nx][ny] == 1)
                            return res;
                        M[100*nx+ny] = 1;
                        v.push_back(100*nx+ny);
                    }
                }
            }
            from = to;
            res += 1;
        }
        return -1;
    }
};