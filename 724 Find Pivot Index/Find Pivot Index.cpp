class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++) {
            sum += nums[i];
        }
        int partsum = 0;
        for(int i = 0;i<nums.size();i++) {
            if(partsum*2+nums[i] == sum)
                return i;
            partsum += nums[i];
        }
        return -1;
    }
};