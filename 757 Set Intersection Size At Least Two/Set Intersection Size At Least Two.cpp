class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return (a[1] < b[1]) || (a[1] == b[1] && a[0] > b[0]);
    }
    
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return 2;
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<int> res;
        for(int i = 0;i<intervals.size();i++) {
            int num = check(res, intervals[i]);
            if(num >= 2)
                continue;
            if(num == 1) {
                res.push_back(intervals[i][1]);    
            }
            else if(num == 0) {
                res.push_back(intervals[i][1]-1); 
                res.push_back(intervals[i][1]); 
            }
        }
        for(int i = 0;i<res.size();i++) {
            cout << res[i] << " ";
        }
        return res.size();
    }
    
    int check(vector<int>& res, vector<int>& inter) {
        if(res.size() == 0)
            return 0;
        int pos1,pos2;
        if(inter[1]<res[0])
            return 0;
        if(inter[0] > res[res.size()-1])
            return 0;
        
        int from = 0; int to = res.size()-1;
        while(from < to) {
            int mid = (from+to)/2;
            if(res[mid] < inter[0])
                from = mid+1;
            else if(res[mid] == inter[0]) {
                pos1 = mid;
                break;
            }
            else {
                to = mid;
            }
        }
        if(from == to)
            pos1 = to;
        
        from = 0;
        to = res.size()-1;
        while(from < to) {
            int mid = (from+to+1)/2;
            if(res[mid] < inter[1])
                from = mid;
            else if(res[mid] == inter[1]) {
                pos2 = mid;
                break;
            }
            else {
                to = mid-1;
            }
        }
        if(from == to)
            pos2 = to;
        
        return pos2-pos1+1;
    }
};