class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int from = 0, to = 0;
        int sum = nums[0];
        int res = INT_MAX;
        while(1)
        {
            if(sum >= s)
            {
                if(res > to-from+1)
                    res = to-from+1;
                if(to == from)
                    return 1;
                sum -= nums[from];
                from++;
            }
            else
            {
                to++;
                if(to < nums.size())
                    sum += nums[to];
                else
                {
                    if(res == INT_MAX)
                        res = 0;
                    return res;
                }
            }
        }
    }
};