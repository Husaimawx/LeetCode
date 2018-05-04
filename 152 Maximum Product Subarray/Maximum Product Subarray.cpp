class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int zerofrom = -1;
        int sign = 1;
        int firstneg = -1;
        int lastneg = -1;
        int res = INT_MIN;
        for(int i = 0; i<=nums.size();i++)
        {
            if(nums[i] == 0 || i == nums.size())
            {
                if(nums[i] == 0)
                    res = max(res,0);
                if(i - zerofrom <= 2)
                {
                    res = max(res, nums[i-1]);
                }
                else if(sign == 1)
                {
                    int temp = 1;
                    for(int j = zerofrom+1;j<i;j++)
                    {
                        temp *= nums[j];
                    }
                    if(temp > res)
                        res = temp;
                }
                else
                {
                    int temp1 = 1;
                    for(int j = zerofrom+1; j<lastneg; j++)
                    {
                        temp1 *= nums[j];
                    }
                    int temp2 = 1;
                    for(int j = firstneg+1; j<i; j++)
                    {
                        temp2 *= nums[j];
                    }
                    res = max(res, max(temp1,temp2));
                }
                sign = 1;
                zerofrom = i;
                firstneg = i;
                lastneg = i;
            }
            else if(nums[i]<0)
            {
                sign *= -1;
                lastneg = i;
                if(firstneg == zerofrom)
                    firstneg = i;
            }
        }
        
        return res;
    }
};