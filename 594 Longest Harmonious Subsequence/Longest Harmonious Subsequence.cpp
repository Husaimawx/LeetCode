class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int num = 0;
        int res = 0;
        int last = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            int c = 1;
            while(i+1<nums.size() && nums[i] == nums[i+1])
            {
                i++;
                c++;
            }
            if(last+1 == nums[i])
            {
                if(res < num+c)
                    res = num+c;
            }
            num = c;
            last = nums[i];
        }
        return res;
    }
};