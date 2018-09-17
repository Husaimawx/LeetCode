class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        map<int,int> M;
        M[0] = -1;
        int res = 0;
        int diff = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i] == 0)
                diff++;
            else
                diff--;
            
            if(M.count(diff) == 0)
                M[diff] = i;
            else
            {
                if(i-M[diff] > res)
                    res = i-M[diff];
            }
        }
        return res;
    }
};