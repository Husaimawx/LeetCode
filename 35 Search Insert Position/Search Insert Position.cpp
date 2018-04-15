class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        if(length == 0)
            return 0;
        if(nums[length-1]<target)
            return length;
        if(nums[0] >= target)
            return 0;
        int from = 0;
        int to = length-1;
        while(from < to)
        {
            int mid = (from+to)/2;
            if(nums[mid]<target)
            {
                from = mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
            else
            {
                to = mid;
            }
        }
        return from;
    }
};