class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        vector<vector<int>> res(nums.size(),vector<int>(nums.size(),0));
        res[0][0] = nums[0]*nums[1];
        res[nums.size()-1][nums.size()-1] = nums[nums.size()-1]*nums[nums.size()-2];
        for(int i = 1;i<nums.size()-1;i++)
        {
            res[i][i] = nums[i-1]*nums[i]*nums[i+1];
        }
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j+i<nums.size();j++)
            {
                for(int k = j;k<=j+i;k++)
                {
                    int temp1,temp2,temp3,temp4;
                    if(j != 0)
                        temp1 = nums[j-1];
                    else
                        temp1 = 1;
                    if(i+j != nums.size()-1)
                        temp2 = nums[i+j+1];
                    else
                        temp2 = 1;
                    if(k != 0)
                        temp3 = res[j][k-1];
                    else
                        temp3 = 0;
                    if(k != nums.size()-1)
                        temp4 = res[k+1][i+j];
                    else
                        temp4 = 0;
                    res[j][i+j] = max(res[j][i+j], nums[k]*temp1*temp2+temp3+temp4);
                }
            }
        }
        return res[0][nums.size()-1];
    }
};  