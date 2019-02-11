class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() < 2)
            return pairs.size();
        
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return (a[1] < b[1]);
        };
        
        sort(pairs.begin(),pairs.end(),comp);
        
        int res = 0;
        int from = INT_MIN;
        int i = 0;
        while(i < pairs.size()) {
            if(pairs[i][0] > from) {
                res++;
                from = pairs[i][1];
                i++;
            } else {
                i++;
            }
        }
        return res;
    }
};