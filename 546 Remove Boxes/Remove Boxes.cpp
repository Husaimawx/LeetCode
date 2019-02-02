class Solution {
public:

public:

    int removeBoxes(vector<int>& boxes) {
        if(boxes.size() == 0)
            return 0;
        vector<pair<int,int>> bx;
        int from = 0;
        while(from < boxes.size()) {
            int to;
            for(to = from+1;to < boxes.size();to++) {
                if(boxes[from] != boxes[to])
                    break;
            }
            bx.push_back(pair<int,int>(boxes[from],to-from));
            from = to;
        }
        
        vector<int> temp(bx.size()+1,0);
        vector<vector<int>> temp2(bx.size()+1,temp);
        vector<vector<vector<int>>> M(bx.size()+1, temp2);
        
        return dfs(bx, M, 0, bx.size()-1, 0);
    }
    
    int dfs(vector<pair<int,int>>& bx, vector<vector<vector<int>>>& M, int i, int j, int k) {
        if(M[i][j][k] != 0)
            return M[i][j][k];
        
        if(i > j) {
            return 0;
        }
        
        int res = (bx[i].second+k)*(bx[i].second+k) + dfs(bx,M,i+1,j,0);
        
        for(int t = i+1;t<=j;t++) {
            if(bx[t].first == bx[i].first) {
                res = max(res,dfs(bx,M,i+1,t-1,0)+dfs(bx,M,t,j,bx[i].second+k));
            }
        }
        
        M[i][j][k] = res;
        return res;
    }
};