class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int penalty = 0;
        int totalnum = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(i == 0 || nums[i] == nums[i-1])
            {
                penalty+=1;
            }
            else
            {
                penalty = 1;
            }
            
            if(penalty <= 2)
            {
                nums[totalnum] = nums[i];
                totalnum++;
            }
        }
        
        return totalnum;
    }
};