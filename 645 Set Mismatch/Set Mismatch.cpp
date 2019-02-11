class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> M;
        int rep = 0;
        for(int i = 0;i<nums.size();i++) {
            if(M.count(nums[i])) {
                rep = nums[i];
                break;
            }
            M[nums[i]] = 1;
        }
        long long sum = 0;
        for(int i = 0;i<nums.size();i++) {
            sum += nums[i];
        }
        sum -= (long long)(nums.size())*(long long)(nums.size()+1)/2;
        vector<int> res(2,0);
        res[0] = rep;
        res[1] = rep-sum;
        return res;
    }
};