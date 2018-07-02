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
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2)
            return intervals;
        
        auto comp = [](Interval& p1, Interval& p2) {
            return (p1.start < p2.start) || (p1.start == p2.start && p1.end < p2.end);
        };
        
        sort(intervals.begin(), intervals.end(), comp);

        int i = 0;
        int max;
        int min;
        vector<Interval> res;
        while(1)
        {
            min = intervals[i].start;
            max = intervals[i].end;
            i++;
            while(i < intervals.size())
            {
                if(max >= intervals[i].start)
                {
                    if(intervals[i].end > max)
                        max = intervals[i].end;
                    i++;
                }
                else
                {
                    res.push_back(Interval(min,max));
                    break;
                }
            }
            if(i == intervals.size())
            {
                res.push_back(Interval(min,max));
                return res;                
            }
        }
        
    }
};