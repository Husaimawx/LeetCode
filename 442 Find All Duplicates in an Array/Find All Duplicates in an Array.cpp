class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.size() < 2)
            return res;
        for(int i = 0;i<nums.size();i++) {
            while(1) {
                if(nums[i] == 0)
                    break;
                if(nums[i] == i+1)
                    break;
                if(nums[i] == nums[nums[i]-1]) {
                    res.push_back(nums[i]);
                    nums[i] = 0;
                    break;
                } else {
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp;
                }
            }
        }
        return res;
    }
};