struct Solution {
    int maxEnvelopes(vector<pair<int, int>>& es) {
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return (a.first<b.first || (a.first == b.first && a.second > b.second));  
        };
        sort(es.begin(),es.end(),comp);
        
        vector<int> dp;
        for(auto e:es) {
            auto iter = lower_bound(dp.begin(),dp.end(),e.second);
            if(iter == dp.end()) {
                dp.push_back(e.second);
            } else {
                if(*iter != e.second) {
                    *iter = e.second;
                }
            }
        }
        return dp.size();
    }
};