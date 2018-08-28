class Solution {
public:
    int minMoves2(vector<int>& nums) {
            auto mid = nums.begin() + nums.size()/2;
            nth_element(nums.begin(), mid, nums.end());
            int median = *mid, count = 0;
            for(int e: nums) count += abs(e-median);
            return count;
    }
};