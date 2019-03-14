class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int from = 0;
        int to = nums.size()-1;
        while(from <= to) {
            int mid = (from+to)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target) {
                from = mid+1;
            } else {
                to = mid-1;
            }
        }
        return -1;
    }
};