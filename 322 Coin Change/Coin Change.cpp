class Solution {
vector<int> res; 
    
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        res.resize(amount+1);
        for(int i = 0;i<=amount;i++)
            res[i] = INT_MAX;
        res[0] = 0;
        
        coinChangeAux(coins, amount);
        return res[amount];
    }
    
    void coinChangeAux(vector<int>& coins, int amount)
    {
        for(int i = 0;i<coins.size();i++)
        {
            if(amount < coins[i])
                break;

            if(res[amount-coins[i]] == INT_MAX)
                coinChangeAux(coins, amount-coins[i]);
            
            if(res[amount-coins[i]] < 0)
                continue;            
            else
            {
                if(res[amount-coins[i]] + 1 < res[amount])
                    res[amount] = res[amount-coins[i]] + 1;
            }
        }
        if(res[amount] == INT_MAX)
            res[amount] = -1;
        return;
    }
};