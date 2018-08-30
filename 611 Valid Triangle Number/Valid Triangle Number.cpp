class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i = 0;i<nums.size()-2;i++)
        {
            int t = i+2;
            for(int j = i+1;j<nums.size()-1;j++)
            {
                if(t <= j)
                    t = j+1;
                while(t<nums.size() && nums[t]<nums[i]+nums[j]) t++;
                res += t-j-1;
            }
        }
        return res;
    }
};