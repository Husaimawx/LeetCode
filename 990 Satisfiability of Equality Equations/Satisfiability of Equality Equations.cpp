class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> v(26);
        for(int i = 0;i<equations.size();i++) {
            if(equations[i][1] == '=' && equations[i][0] != equations[i][3]) {
                v[int(equations[i][0]-'a')].push_back(equations[i][3]-'a');
                v[int(equations[i][3]-'a')].push_back(equations[i][0]-'a');
            }
        }
        int base = 1;
        map<int,int> M;
        int st = 0;
        while(st < 26) {
            if(M.count(st) != 0) {
                st += 1;
                continue;
            }
            vector<int> dq(1,st);
            M[st] = base;
            int from = 0;
            while(from != dq.size()) {
                int to = dq.size();
                for(int i = from;i<to;i++) {
                    for(int j = 0;j<v[dq[i]].size();j++) {
                        if(M.count(v[dq[i]][j]) == 0) {
                            M[v[dq[i]][j]] = base;
                            dq.push_back(v[dq[i]][j]);
                        }
                    }
                }
                from = to;
            }
            st += 1;
            base += 1;
        }

        for(int i = 0;i<equations.size();i++) {
            if(equations[i][1] == '!') {
                if(M[equations[i][0]-'a'] == M[equations[i][3]-'a'])
                    return false;
            }
        }
        return true;
    }
};