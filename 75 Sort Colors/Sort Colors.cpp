class Solution {
public:
    void sortColors(vector<int>& nums) {
        int from = 0, to = nums.size()-1;
        for(int i = 0; i<=to;)
        {
            if(nums[i] == 2)
            {
                swap(nums[i],nums[to]);
                to--;
            }
            else if(nums[i] == 0)
            {
                swap(nums[i],nums[from]);
                from++;
                i++;
            }
            else
            {
                i++;
            }
        }
        return;
    }
};