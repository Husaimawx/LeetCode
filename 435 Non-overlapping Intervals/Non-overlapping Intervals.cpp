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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int size = intervals.size();
        if(size <= 1)
            return 0;
        
        auto comp = [](Interval& p1, Interval& p2) {
            return (p1.end < p2.end);
        };
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int right = intervals[0].end;
        int res = 0;
        for(int i = 1;i<size;i++)
        {
            if(intervals[i].start < right)
                res++;
            else
            {
                right = intervals[i].end;
            }
        }
        return res;
    }
};