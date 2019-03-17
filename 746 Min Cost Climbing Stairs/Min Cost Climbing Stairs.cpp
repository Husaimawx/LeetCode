class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size(), 0);
        res[cost.size()-1] = cost[cost.size()-1];
        res[cost.size()-2] = cost[cost.size()-2];
        for(int i = (int)(cost.size())-3;i>=0;i--) {
            res[i] = cost[i] + min(res[i+1], res[i+2]);
        }
        return min(res[0],res[1]);
    }
};