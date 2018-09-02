// DFS
class Solution {
vector<int> sum;
int target;
    
public:
    bool makesquare(vector<int>& nums) {
        int sum0 = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum.push_back(0);
            sum0 += nums[i];
        }
        if(sum0 % 4 != 0)
            return false;
        target = sum0/4;
        return DFS(nums,0);
    }
    
    bool DFS(vector<int>& nums, int from)
    {
        if(from == nums.size())
            return false;
        if((sum[0] == target)+(sum[1] == target)+(sum[2] == target)+(sum[3] == target)>=3)
            return true;
        for(int i = 0;i<4;i++)
        {
            if(sum[i] == target || sum[i]+nums[from]>target)
                continue;
            sum[i] += nums[from];
            if(DFS(nums,from+1))
                return true;
            sum[i] -= nums[from];
        }
        return false;
    }
};

// DP
class Solution {
public:
    bool makesquare(vector<int>& nums2) {
        vector<int> nums;
        nums.assign(nums2.begin(), nums2.end());
        if(nums.empty()) return false;
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4 != 0)
            return false;
        int side = sum / 4;
        vector<bool> used;
        used.resize(nums.size());
        return helper(nums, 0, used, 4, 0, side);
        
    }
    
    bool helper(vector<int>& nums, int index, vector<bool>& used, int k, int sum, int target){
        if(k == 0)
            return true;
        if(sum == target)
            return helper(nums, 0, used, k - 1, 0, target);
        
        for(int i = index; i < nums.size(); ++i){
            if(used[i] || (i > 0 && nums[i - 1] == nums[i] && !used[i - 1])) continue;
            if(sum + nums[i] > target) break;
            used[i] = true;
            if(helper(nums, i + 1, used, k, sum + nums[i], target)) return true;
            used[i] = false;
        }
        return false;
    }
};