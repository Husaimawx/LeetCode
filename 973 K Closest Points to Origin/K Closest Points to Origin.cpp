class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int,vector<vector<int>>> M;
        for(int i = 0;i<points.size();i++) {
            if(M.count(points[i][0]*points[i][0]+points[i][1]*points[i][1]) == 0) {
                vector<vector<int>> temp;
                M[points[i][0]*points[i][0]+points[i][1]*points[i][1]] = temp;
            }
            M[points[i][0]*points[i][0]+points[i][1]*points[i][1]].push_back(points[i]);
        }
        vector<vector<int>> res;
        for(auto iter = M.begin();iter != M.end();iter++) {
            for(int i = 0;i<iter->second.size();i++) {
                res.push_back(iter->second[i]);
                K--;
                if(K == 0)
                    return res;
            }
        }
        return res;
    }
};