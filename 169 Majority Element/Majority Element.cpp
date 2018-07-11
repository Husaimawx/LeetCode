class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxnum = nums[0],maxtime = 1;
        int time = 1;
        for(int i = 1;i<=nums.size()+1;i++)
        {
            if(i == nums.size() || nums[i] != nums[i-1])
            {
                if(time > maxtime)
                {
                    maxtime = time;
                    maxnum = nums[i-1];
                }
                time = 1;
            }
            else
            {
                time+=1;
            }
        }
        return maxnum;
    }
};