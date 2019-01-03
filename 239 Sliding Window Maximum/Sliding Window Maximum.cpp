class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size() == 0 || k <=0 || nums.size() < k)
            return res;
        if(k == 1)
            return nums;
        deque<int> dq;
        for(int i = 0;i<nums.size();i++) {
            if(i == 0) {
                dq.push_back(nums[i]);
                continue;
            }
            
            if(i>=k && nums[i-k] == dq[0])
                dq.pop_front();
            while(dq.size() != 0 && dq[dq.size()-1] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            
            if(i+1 >= k)
                res.push_back(dq[0]);
        }
        return res;
    }
};