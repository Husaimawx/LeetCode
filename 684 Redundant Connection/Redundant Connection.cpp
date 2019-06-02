 class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> num(n);
        for(int i = 0;i<n;i++) {
            num[i] = i;
        }
        for(int i = 0;i<n;i++) {
            if(concat(edges[i][0]-1,edges[i][1]-1,num))
                return edges[i];
        }
        return edges[0];
    }
    
    int find(int i, vector<int>& num) {
        return num[i] == i ? i : find(num[i], num);
    }
    
    bool concat(int i, int j, vector<int>& num) {
        int hi = find(i,num);
        int hj = find(j,num);
        if(hi == hj)
            return true;
        else {
            num[hi] = hj;
            return false;
        }
    }
};