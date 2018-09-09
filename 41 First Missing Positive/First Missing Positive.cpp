class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        
        int k = nums.size();
        for(int from = 0;from < k;from++)
        {
            if(nums[from] <= 0 || nums[from]>k || nums[from] == from+1)
                continue;
            
            int oldvalue;
            while(1)
            {
                oldvalue = nums[from];
                swap(nums,from,nums[from]-1);
                if(oldvalue == nums[from])
                {
                    nums[from] = -1;
                    break;   
                }
                if(nums[from] <= 0 || nums[from]>k || nums[from] == from+1)
                    break;
            }
        }
        
        for(int i = 0;i<k;i++)
        {
            if(nums[i] <=0 || nums[i]>k)
                return i+1;
        }
        return k+1;
    }
    
    void swap(vector<int>& nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        return;
    }
};