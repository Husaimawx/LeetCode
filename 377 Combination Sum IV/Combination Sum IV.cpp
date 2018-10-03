// 组合
class Solution {
unordered_map<long long int, int> M;
int maxtarget;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        maxtarget = target+1;
        sort(nums.begin(),nums.end());
        int to;
        for(to = 0;to<nums.size();to++)
        {
            if(nums[to] > target)
                break;
        }
        to--;
        return combinationSum4Aux(nums, to, target);
    }
    
    int combinationSum4Aux(vector<int>& nums, int to, int target)
    {
        if(target == 0)
            return 1;
        if(to == 0)
        {
            if(target % nums[0] == 0)
                return 1;
            else
                return 0;
        }
        if(M.count(maxtarget*to+target) > 0)
            return M[maxtarget*to+target];
        int type = target/nums[to];
        int res = 0;
        for(int i = 0;i<=type;i++)
        {
            res+=combinationSum4Aux(nums,to-1,target-i*nums[to]);
        }
        M[maxtarget*to+target] = res;
        return res;
    }
};

// 排序
class Solution {
unordered_map<int, int> M;
int maxtarget;
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        maxtarget = target+1;
        sort(nums.begin(),nums.end());
        int to;
        for(to = 0;to<nums.size();to++)
        {
            if(nums[to] > target)
                break;
        }
        to--;
        return combinationSum4Aux(nums, to, target);
    }
    
    int combinationSum4Aux(vector<int>& nums, int to, int target)
    {
        if(target == 0)
            return 1;
        if(M.count(target) != 0)
            return M[target];
        int res = 0;
        for(int i = 0;i<=to;i++)
        {
            if(nums[i] > target)
                break;
            res += combinationSum4Aux(nums, to, target-nums[i]);
        }
        M[target] = res;
        return res;
    }
};