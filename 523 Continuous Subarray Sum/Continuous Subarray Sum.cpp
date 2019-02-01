class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long,int> M;
        M[0] = -1;
        long sum = 0;
        
        if(k != 0) {
            for(int i = 0;i<nums.size();i++) {
                sum += nums[i];
                sum = sum % k;
                if(M.count(sum) != 0) {
                    if(M[sum]+1 != i)
                        return true;
                } else
                    M[sum] = i;
            }
            return false;            
        } else {
            for(int i = 0;i<nums.size();i++) {
                sum += long(nums[i]);
                if(M.count(sum) != 0) {
                    if(M[sum]+1 != i)
                        return true;
                } else
                    M[sum] = i;
            }
            return false;               
        }

    }
};