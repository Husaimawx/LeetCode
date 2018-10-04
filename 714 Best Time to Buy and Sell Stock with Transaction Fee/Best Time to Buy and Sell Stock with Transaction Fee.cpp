class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1)
            return 0;
        vector<int> res(prices.size()+1,0);
        vector<int> pos;
        vector<int> value;
        int top = 0;
        pos.push_back(0);
        value.push_back(prices[0]);
        for(int i = 1;i<prices.size();i++)
        {
            res[i+1] = res[i];
            int j;
            for(j = top;j>=0;j--)
            {
                if(value[j] < prices[i])
                    break;
            }
            for(int t = 0;t<=j;t++)
            {
                if(prices[i] > prices[pos[t]])
                {
                    res[i+1] = max(res[i+1],prices[i]-prices[pos[t]]+res[pos[t]]-fee);
                }
            }
            top = j+1;
            if(pos.size() > j+1)
            {
                pos[j+1] = i;
                value[j+1] = prices[i];
            }
            else
            {
                pos.push_back(i);
                value.push_back(prices[i]);
            }
        }
        return res[prices.size()];
    }
};