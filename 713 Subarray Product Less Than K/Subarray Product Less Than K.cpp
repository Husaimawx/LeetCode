class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        long from = 0;
        long to = 0;
        int base = 1;
        long res = 0;
        
        for(;from < nums.size();from++) {
            while(base * nums[to] < k) {
                base *= nums[to];
                to += 1;
                if(to == nums.size()) {
                    return res + (to-from)*(to-from+1)/2;
                }
            }
            res += (to-from);
            if(from != to)
                base /= nums[from];
            else
                to++;
        }
        return res;
    }
};