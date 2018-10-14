// O(n^m)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i] == 0)
            {
                res[i] = INT_MAX;
                continue;
            }
            int maxpos = min(int(nums.size())-1, i+nums[i]);
            int min = INT_MAX;
            for(int j = i+1;j<=maxpos;j++)
            {
                if(res[j] < min)
                    min = res[j];
            }
            if(min == INT_MAX)
                res[i] = min;
            else
                res[i] = min+1;
        }
        return res[0];
    }
};

//O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        vector<int> res(nums.size(),INT_MAX);
        res[0] = 0;
        deque<int> dq;
        dq.push_back(res[0]);
        
        while(dq.size() != 0)
        {
            int now = dq[0];
            if(nums[now] == 0)
            {
                dq.pop_front();
                continue;
            }
            int from = dq[dq.size()-1]+1;
            int to = min(int(nums.size())-1,now+nums[now]);
            for(int i = from;i<=to;i++)
            {
                res[i] = res[now]+1;
                if(i == nums.size()-1)
                    return res[i];
                dq.push_back(i);
            }
            dq.pop_front();
        }
    }
};