class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int size = points.size();
        if(size <= 1)
            return size;
        
        auto comp = [](pair<int, int>& p1, pair<int, int>& p2) {
            return (p1.second < p2.second);
        };
        
        sort(points.begin(), points.end(), comp);
        
        int right = points[0].second;
        int res = 0;
        for(int i = 1;i<size;i++)
        {
            if(points[i].first <= right)
                res++;
            else
            {
                right = points[i].second;
            }
        }
        return (size-res);        
    }
};