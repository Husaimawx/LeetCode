class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return subsearch(nums,target,0,nums.size()-1);
    }
    
    int subsearch(vector<int>& nums, int target, int from, int to)
    {
        if(from == to)
        {
            if(nums[from] == target)
                return from;
            else
                return -1;
        }
        if(from + 1 == to)
        {
            if(nums[from] == target)
                return from;
            else if(nums[to] == target)
                return to;
            else
                return -1;           
        }
        if(nums[from] < nums[to])
        {
            while(from <= to)
            {
                int mid = (from+to)/2;
                if(nums[mid] == target)
                    return mid;
                else if(nums[mid] < target)
                    from = mid+1;
                else
                    to = mid-1;
            }
            return -1;
        }
        else
        {
            int mid = (from+to)/2;
            if(nums[mid] == target)
                return mid;
            else
            {
                int a = subsearch(nums,target,from,mid-1);
                if(a != -1)
                    return a;
                else
                {
                    return subsearch(nums,target,mid+1,to);
                }
            }
        }

    }
};