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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i;
        vector<Interval> res;
        for(i = 0;i<intervals.size();i++)
        {
            if(intervals[i].end >= newInterval.start)
                break;
            res.push_back(intervals[i]);
        }
        if(i == intervals.size())
        {
            res.push_back(newInterval);
            return res;
        }
        int start = min(intervals[i].start,newInterval.start);
        int j;
        for(j = i;j<intervals.size();j++)
        {
            if(intervals[j].end >= newInterval.end)
                break;
        }
        if(j == intervals.size())
        {
            res.push_back(Interval(start, newInterval.end));
            return res;
        }
        
        if(intervals[j].start > newInterval.end)
        {
            res.push_back(Interval(start, newInterval.end));
        }
        else
        {
            res.push_back(Interval(start, intervals[j].end));
            j++;
        }
        
        for(;j<intervals.size();j++)
        {
            res.push_back(intervals[j]);
        }
        
        return res;
    }
};