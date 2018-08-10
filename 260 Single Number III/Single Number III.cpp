class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            temp = temp ^ nums[i];
        }
        int temp2 = 2;
        while(temp%temp2==0)
            temp2*=2;
        temp2 /= 2;
        
        vector<int> group1;
        vector<int> group2;
        for(int i = 0;i<nums.size();i++)
        {
            if((nums[i] & temp2) == 0)
            {
                group1.push_back(nums[i]);
            }
            else
            {
                group2.push_back(nums[i]);
            }
        }
        
        vector<int> res(2,0);
        res[0] = singleNumberAux(group1);
        res[1] = singleNumberAux(group2);
        return res;
    }
    
    int singleNumberAux(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            res = res ^ nums[i];
        }
        return res;
    }
};