// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> res(nums.size(), 1);
        for(int i = 1;i<nums.size();i++)
        {
            int max = 0;
            for(int j = 0;j<i;j++)
            {
                if(res[j]>max && nums[j]<nums[i])
                    max = res[j];
            }
            res[i] = max+1;
        }
        int max = 0;
        for(int i = 0;i<nums.size();i++)
            if(res[i] > max)
                max = res[i];
        return max;
    }
};


// O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for(int i = 0;i<nums.size();i++)
        {
            int pos = find(tail,nums[i]);
            if(pos == -1)
                tail.push_back(nums[i]);
            else
                tail[pos] = nums[i];
        }
        return tail.size();
    }
    
    int find(vector<int>& tail, int num)
    {
        int i;
        for(i = 0;i<tail.size();i++)
        {
            if(tail[i]>=num)
                break;
        }
        if(i == tail.size())
            return -1;
        else
            return i;
    }
};