class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if(prices.size() < 2)
            return 0;
        vector<int> min1(prices.size(),prices[0]);
        for(int i = 1;i<prices.size();i++) {
            min1[i] = min(min1[i-1],prices[i]);
        }
        
        vector<int> onetime(prices.size(),prices[1]-prices[0]);
        for(int i = 2;i<prices.size();i++) {
            onetime[i] = max(onetime[i-1],prices[i]-min1[i-1]);
        }
        res = max(res,onetime[onetime.size()-1]);
        
        if(prices.size() < 4)
            return res;
        vector<int> twotime(prices.size(),onetime[1]-prices[2]);
        for(int i = 3;i<prices.size();i++) {
            twotime[i] = max(twotime[i-1], onetime[i-1]-prices[i]);
        }
        
        for(int i = 3;i<prices.size();i++)
            res = max(res, prices[i]+twotime[i-1]);
        return res;
    }
};