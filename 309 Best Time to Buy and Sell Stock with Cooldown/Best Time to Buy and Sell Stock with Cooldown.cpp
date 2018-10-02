class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        
        vector<int> res(3,0);
        for(int i = 1;i<prices.size();i++)
        {
            res.push_back(res[i+1]);
            int temp = prices[i];
            for(int j = i-1;j>=0;j--)
            {
                if(prices[j] < temp)
                {
                    if(prices[i]-prices[j]+res[j]>res[i+2])
                    {
                        res[i+2] = prices[i]-prices[j]+res[j];
                    }
                    temp = prices[j];
                }
            }
        }
        
        return res[res.size()-1];
    }
};