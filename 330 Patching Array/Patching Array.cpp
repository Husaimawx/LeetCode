class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        if(n<1)
            return 0;
        
        int res = 0;
        int data = 2;
        int from = 1;
        if(nums.size() == 0 || nums[0] != 1) {
            res = 1;
            from = 0;
        }
        while(data > 0 && data <= n) {
            if(from < nums.size() && data >= nums[from]) {
                data = data+nums[from];
                from++;
            } else {
                res += 1;
                data = data*2;
            }
        }
        return res;
    }
};