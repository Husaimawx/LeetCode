class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int from = 0, to = nums.size()-1;
        while(from+1<to)
        {
            if(nums[from]<nums[to])
                return nums[from];
            int mid = (from+to)/2;
            if(nums[mid]<nums[from])
            {
                to = mid;
            }
            else if(nums[mid]>nums[from])
            {
                from = mid+1;
            }
            else
            {
                if(nums[from] == nums[to])
                {
                    int min = nums[from];
                    for(int i = from+1;i<to;i++)
                    {
                        if(nums[i]<min)
                            min = nums[i];
                    }
                    return min;
                }
                else
                {
                    from = mid+1;
                }
            }
        }
        
        if(from == to)
            return nums[from];
        
        if(nums[from]<nums[to])
            return nums[from];
        else
            return nums[to];
    }
};