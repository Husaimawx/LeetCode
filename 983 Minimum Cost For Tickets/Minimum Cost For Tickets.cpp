class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        costs[1] = min(costs[1],costs[2]);
        costs[0] = min(costs[1],costs[0]);
        vector<int> money(days[days.size()-1]+1, costs[0]);
        vector<int> date(money.size(), 0);
        for(int i : days) {
            date[i] = 1;
        }
        for(int i = int(money.size())-2;i>=1;i--) {
            if(date[i] == 0)
                money[i] = money[i+1];
            else {
                money[i] += money[i+1];
                int base;
                if(i+7 < money.size())
                    base = money[i+7];
                else
                    base = 0;
                money[i] = min(money[i],base+costs[1]);
                if(i+30 < money.size())
                    base = money[i+30];
                else
                    base = 0;
                money[i] = min(money[i],base+costs[2]);
            }
        }
        return money[1];
    }
};