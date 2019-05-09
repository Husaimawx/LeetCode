class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<int> temp;
        vector<vector<int>> v(n*n*4, temp);
        for(int i = 1;i<=n*n*4-7;i+=4) {
            if((i+3)%(4*n) != 0) {
                v[i].push_back(i+6);
                v[i+6].push_back(i);
            }
        }
        for(int i = 2;i<=4*n*(n-1)-2;i+=4) {
            v[i].push_back(i+4*n-2);
            v[i+4*n-2].push_back(i);
        }
        
        for(int i = 0;i<n;i++) {    
            for(int j = 0;j<n;j++) {
                int base = 4*n*i+4*j;
                if(grid[i][j] == ' ') {
                    v[base].push_back(base+1);
                    v[base+1].push_back(base);
                    v[base+1].push_back(base+2);
                    v[base+2].push_back(base+1);
                    v[base+2].push_back(base+3);
                    v[base+3].push_back(base+2);
                } else if(grid[i][j] == '\\') { 
                    v[base].push_back(base+1);
                    v[base+1].push_back(base);
                    v[base+2].push_back(base+3);
                    v[base+3].push_back(base+2);
                } else {
                    v[base+1].push_back(base+2);
                    v[base+2].push_back(base+1);
                    v[base].push_back(base+3);
                    v[base+3].push_back(base);
                }
            }
        }
        int res = 0;
        int st = 0;
        map<int,int> M;
        //for(int i = 0;i<16;i++) {
        //    for(int j = 0;j<v[i].size();j++) {
        //        cout << v[i][j];
        //    }
        //    cout << endl;
        //}

        while(M.size() != n*n*4) {
            if(M.count(st) != 0) {
                st += 1;
                continue;
            }
            vector<int> vec(1,st);
            M[st] = 1;
            int from = 0;
            while(from != vec.size()) {
                int to = vec.size();
                for(int i = from;i<to;i++) {
                    for(int j = 0;j<v[vec[i]].size();j++) {
                        if(M.count(v[vec[i]][j]) == 0) {
                            vec.push_back(v[vec[i]][j]);
                            M[v[vec[i]][j]] = 1;
                        }
                    }
                }
                from = to;
            }
            res += 1;
        }
        return res;
    }
};