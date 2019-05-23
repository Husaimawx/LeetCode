class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_map<int,int> M;
        for(int i = 0;i<nums.size();i++) {
            M[nums[i]] = 1;
        }
        
        int res = 1;
        for(int i = 0;i<nums.size();i++) {
            if(M.count(nums[i]-1) != 0)
                continue;

            int j;
            for(j = 1;;j++) {
                if(M.count(nums[i]+j) == 0) 
                    break;
            }
            int t;
            for(t = 1;;t++) {
                if(M.count(nums[i]+j) == 0) 
                    break;
            }
            res = max(res,t+j-1);
        }
        return res;
    }
};