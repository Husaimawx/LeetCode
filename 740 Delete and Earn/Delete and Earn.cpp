class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> res(10000,-1);
        vector<int> hash(10000,0);
        int max = 0;
        for(int i = 0;i<nums.size();i++)
        {
            hash[nums[i]-1]+=1;
            if(nums[i] > max)
                max = nums[i];
        }
        for(int i = 0;i<max;i++)
        {
            if(i == 0)
                res[0] = hash[0];
            else if(i == 1)
            {
                res[1] = 2*hash[1];
                if(res[0]>res[1])
                    res[1] = res[0];
            }
            else
            {
                res[i] = res[i-2]+hash[i]*(i+1);
                if(res[i-1] > res[i])
                    res[i] = res[i-1];
            }
        }
        return res[max-1];
    }
};