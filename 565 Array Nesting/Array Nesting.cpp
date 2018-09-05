class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> flag(nums.size(),0);
        int from;
        int res = 0;
        for(from = 0;from < nums.size();from++)
        {  
            if(flag[from] == 1)
                continue;
            int start = from;
            int time = 0;
            while(1)
            {
                if(flag[start] == 1)
                    break;
                time += 1;
                flag[start] = 1;
                start = nums[start];
            }
            if(res < time)
                res = time;
        }
        return res;
    }
};