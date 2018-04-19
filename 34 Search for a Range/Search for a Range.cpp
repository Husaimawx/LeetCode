class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int len = nums.size();
        if(len == 0)
            return ans;
        int from = 0;
        int to = len-1;
        int mid;
        
        if(nums[0]>target || nums[to]<target)
            return ans;
        while(from <= to)
        {
            mid = (from+to)/2;
            if(nums[mid] < target)
            {
                from = mid+1;
            }
            else if(nums[mid] > target)
            {
                to = mid-1;
            }
            else
            {
                int temp;
                int tempto = mid;
                int tempfrom = mid;
                while(from <= tempto)
                {
                    temp = (from+tempto)/2;
                    if(nums[temp]<target)
                        from = temp+1;
                    else if(nums[temp]>target)
                        tempto = temp-1;
                    else if(temp==0 || nums[temp-1]<target)
                    {
                        from = temp;
                        break;
                    }
                    else
                    {
                        tempto = temp-1;
                    }        
                }
                
                while(to >= tempfrom)
                {
                    temp = (to+tempfrom)/2;
                    if(nums[temp]<target)
                        tempfrom = temp+1;
                    else if(nums[temp]>target)
                        to = temp-1;
                    else if(temp+1==len || nums[temp+1]>target)
                    {
                        to = temp;
                        break;
                    }
                    else
                    {
                        tempfrom = temp+1;
                    }        
                }
                break;
            }
        }
        if(from <= to)
        {
            ans[0] = from;
            ans[1] = to;   
        }
        return ans;
    }
};