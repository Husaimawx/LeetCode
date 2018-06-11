class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = 0,p2 = 0;
        while(1)
        {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
            if(p1 == p2)
                break;
        }
        
        p1 = 0;
        while(p1 != p2)
        {
            p1 = nums[p1];
            p2 = nums[p2];
        }
        return p1;
    }
};