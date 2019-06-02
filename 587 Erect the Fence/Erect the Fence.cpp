class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> res;
        for(int i = 0;i<points.size();i++) {
            while(res.size() > 1 && orientation(res[res.size()-2],res[res.size()-1],points[i]) < 0)
                res.pop_back();
            res.push_back(points[i]);
        }
        
        if(res.size() == points.size())
            return res;
        
        for(int i = points.size()-2;i>=0;i--) {
            while(res.size() > 1 && orientation(res[res.size()-2],res[res.size()-1],points[i]) < 0)
                res.pop_back();
            res.push_back(points[i]);
        }        
        
        res.pop_back();
        return res;
    }
    
    int orientation(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0]-a[0])*(c[1]-b[1]) - (b[1]-a[1])*(c[0]-b[0]);
    }
};