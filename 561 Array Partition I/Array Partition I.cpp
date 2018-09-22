class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int size = nums.size();
        int res = 0;
        for(int i = 0;i<size;i+=2)
        {
            res += nums[i];
        }
        
        return res;
    }
};