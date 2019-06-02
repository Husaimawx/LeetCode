class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> num(n,0);
        unordered_map<int,int> M;
        int first = 0;
        int second = 0;
        int base = 0;
        for(int i = 0;i<edges.size();i++) {
            num[edges[i][0]-1]+=1;
            num[edges[i][1]-1]+=1;
            if(M.count(edges[i][1]-1) == 0)
                M[edges[i][1]-1] = edges[i][0]-1;
            else {
                first = M[edges[i][1]-1];
                second = edges[i][0]-1;
                base = edges[i][1];
            }
        }
        //cout << base << first << second;
        if(base == 0) {
            for(int i = n-1;i>=0;i--) {
                if(num[edges[i][0]-1] != 1 && num[edges[i][1]-1] != 1)
                    return edges[i];
            }
        }
        vector<int> res{0,base};
        if(!check(second+1, base, edges)) {
            res[0] = first+1;    
        } else {
            res[0] = second+1;
        }
        return res;
    }
    
    bool check(int a, int b, vector<vector<int>>& edges) {
        vector<vector<int>> num(edges.size());
        for(int i = 0;i<edges.size();i++) {
            if(edges[i][0] == a && edges[i][1] == b) {
                //cout << a << b;
                continue;
            }
            num[edges[i][0]-1].push_back(edges[i][1]-1);
            num[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        //for(int i = 0;i<num.size();i++) {
        //    for(int j = 0;j<num[i].size();j++)
        //        cout << num[i][j];
        //    cout << endl;
        //}
        vector<int> v(1,0);
        int from = 0;
        map<int,int> M;
        M[0] = 1;
        while(from != v.size()) {
            int to = v.size();
            for(int i = from;i<to;i++) {
                for(int j = 0;j<num[v[i]].size();j++) {
                    if(M.count(num[v[i]][j]) == 0) {
                        v.push_back(num[v[i]][j]);
                        M[num[v[i]][j]] = 1;
                    }
                }
            }
            from = to;
        }
        //cout << v.size();
        return v.size() == edges.size();
    }
};