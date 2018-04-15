class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int now = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] != val)
            {
                nums[now] = nums[i];
                now++;
            }
        }
        return now;
    }
};