class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size()<3)
            return 0;
        sort(nums.begin(), nums.end());
        vector<int> slimnums;
        int dulpnum = 1;
        int lastinsert = nums[0];
        for (int i = 1; i<=nums.size(); i++)
        {
            if(i == nums.size() || nums[i] != lastinsert)
            {
                if (dulpnum >= 3)
                {
                    slimnums.push_back(lastinsert);
                    slimnums.push_back(lastinsert);
                    slimnums.push_back(lastinsert);
                }
                else if(dulpnum == 1)
                {
                    slimnums.push_back(lastinsert);
                }
                else
                {
                    slimnums.push_back(lastinsert);
                    slimnums.push_back(lastinsert);
                }
                dulpnum = 1;
                lastinsert = nums[i];
            }
            else
                dulpnum++;
        }
        nums = slimnums;
        
        
        int ans = INT_MAX;
        int diff = INT_MAX;
        int sumnow;
        int lastnumi = INT_MIN;
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] == lastnumi)
                continue;
            else
                lastnumi = nums[i];
            
            int from = i + 1;
            int to = nums.size() - 1;
            while (from < to)
            {
                sumnow = nums[from] + nums[to] + nums[i];
                if (abs(sumnow - target)<diff)
                {
                    ans = sumnow;
                    diff = abs(sumnow - target);
                }
                if (sumnow == target)
                    return target;
                else if (sumnow < target)
                {
                    int last = nums[from];
                    while (from < to && nums[from] == last)
                        from++;
                }
                else
                {
                    int last = nums[to];
                    while (from < to && nums[to] == last)
                        to--;
                }
            }
        }
        
        return ans;       
    }
};