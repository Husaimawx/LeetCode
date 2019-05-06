class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,int> M;
        for(int i = 0;i<points.size();i++) {
            M[points[i][0]*1000+points[i][1]] = 1;
        }
        int res = INT_MAX;
        for(int i = 0;i<points.size();i++) {
            for(int j = i+1;j<points.size();j++) {
                if(points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if(M.count(points[i][0]*1000+points[j][1])==1 && M.count(points[j][0]*1000+points[i][1])==1)
                    res = min(res, abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
            }
        }
        if(res == INT_MAX)
            return 0;
        return res;
    }
};