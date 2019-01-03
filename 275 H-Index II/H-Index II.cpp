class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        int size = citations.size();
        int from = 0;
        int to = min(citations[size-1],size);
        while(from < to) {
            int mid = (from+to+1)/2;
            if(citations[size-mid]>=mid)
                from = mid;
            else
                to = mid-1;
        }
        return from;
    }
};