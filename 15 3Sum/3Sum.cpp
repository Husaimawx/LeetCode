class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size()<3)
            return ans;
        sort(nums.begin(), nums.end());
        vector<int> slimnums;
        int dulpnum = 1;
        int lastinsert = nums[0];
        for (int i = 1; i<=nums.size(); i++)
        {
            if(i == nums.size() || nums[i] != lastinsert)
            {
                if (dulpnum >= 2)
                {
   		            if (lastinsert == 0 && dulpnum!=2)
                    {
                        slimnums.push_back(0);
                        slimnums.push_back(0);
                        slimnums.push_back(0);
                    }
                    else
                    {
                        slimnums.push_back(lastinsert);
                        slimnums.push_back(lastinsert);
                    }
                }
                else
                {
                    slimnums.push_back(lastinsert);
                }
                dulpnum = 1;
                lastinsert = nums[i];
            }
            else
                dulpnum++;
        }

        nums = slimnums;
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
                if (nums[from] + nums[to] + nums[i] == 0)
                {
                    vector<int> temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[from];
                    temp[2] = nums[to];
                    ans.push_back(temp);

                    int last = nums[from];
                    while (from < to && nums[from] == last)
                        from++;
                    to--;
                }
                else if (nums[from] + nums[to] + nums[i] > 0)
                {
                    to--;
                }
                else
                {
                    from++;
                }
            }
        }
        return ans;
    }
};