class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<pair<int,int>> res(nums.size(),pair<int,int>(1,1));
        for(int i = 1;i<nums.size();i++) {
            for(int j = 0;j<i;j++) {
                if(nums[i] > nums[j]) {
                    if(res[i].first <= res[j].first) {
                        res[i].first = res[j].first+1;
                        res[i].second = res[j].second;
                    } else if(res[i].first == res[j].first+1) {
                        res[i].second += res[j].second;
                    }
                }
            }
        }
        int maxnum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++) {
            if(res[i].first > maxnum) {
                maxnum = res[i].first;
                ans = res[i].second;
            } else if(res[i].first == maxnum) {
                ans += res[i].second;
            }
        }
        return ans;
    }
};