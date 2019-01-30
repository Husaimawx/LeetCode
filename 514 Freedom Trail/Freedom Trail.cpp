class Solution {
public:
    int findRotateSteps(string ring, string key) {
        if(key.size() == 0)
            return 0;
        
        vector<int> temp(ring.size(),0);
        vector<vector<int>> DP(key.size(),temp);
        
        map<int, vector<int>> M;
        for(int i = 'a';i<='z';i++) {
            vector<int> temp;
            M[i] = temp;
        }
        for(int i = 0;i<ring.size();i++) {
            M[ring[i]].push_back(i);
        }
        
        for(int i = 0;i<ring.size();i++) {
            int res = INT_MAX;
            for(int j = 0;j<M[key[key.size()-1]].size();j++) {
                res = min(res,abs(i-M[key[key.size()-1]][j]));
                res = min(res,int(ring.size())-abs(i-M[key[key.size()-1]][j]));
            }
            DP[key.size()-1][i] = res;
        }
        
        for(int k = int(key.size())-2;k>=0;k--) {
            for(int i = 0;i<ring.size();i++) {
                int res = INT_MAX;
                for(int j = 0;j<M[key[k]].size();j++) {
                    res = min(res,abs(i-M[key[k]][j])+DP[k+1][M[key[k]][j]]);
                    res = min(res,int(ring.size())-abs(i-M[key[k]][j])+DP[k+1][M[key[k]][j]]);
                }
                DP[k][i] = res;  
            }
        }
        
        return DP[0][0]+key.size();
    }
};