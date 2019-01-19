/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res;
        if(intervals.size()==0) 
            return res;
        
        vector<pair<int,int>> S;
        map<int,int> M;

        for(int i = 0;i<intervals.size();i++) {
            if(M.count(intervals[i].start) == 0) {
                S.push_back(pair<int,int>(intervals[i].start,i));
                M[intervals[i].start] = 1;
            }
        }
        
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return (a.first < b.first);
        };
        
        sort(S.begin(),S.end(),comp);
        
        for (int i = 0;i<intervals.size();i++) {
            if(intervals[i].end > S[S.size()-1].first) {
                res.push_back(-1);
                continue;
            }
            int from = 0;
            int to = S.size()-1;
            while(from<to) {
                int mid = (from+to)/2;
                if(S[mid].first < intervals[i].end)
                    from = mid+1;
                else
                    to = mid;
            }
            res.push_back(S[from].second);
        }
        return res;
    }
};