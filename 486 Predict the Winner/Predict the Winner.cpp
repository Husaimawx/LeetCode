class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size() == 0)
            return false;
        vector<int> temp(nums.size(),0);
        vector<vector<int>> res(nums.size(),temp);
        
        for(int i = 0;i<nums.size();i++) {
            res[i][i] = nums[i];
        }
        
        for(int dis = 1;dis<nums.size();dis++) {
            for(int from = 0;from+dis < nums.size();from++) {
                int res1 = nums[from]-res[from+1][from+dis];
                int res2 = nums[from+dis]-res[from][from+dis-1];
                res[from][from+dis] = max(res1,res2);
            }
        }
        
        
        if(res[0][nums.size()-1]>=0)
            return true;
        return false;
    }
};