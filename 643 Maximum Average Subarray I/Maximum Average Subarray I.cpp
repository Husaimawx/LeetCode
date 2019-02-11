class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum = 0;
        long long res = 0;
        for(int i = 0;i<k;i++)
            sum += (long long)(nums[i]);
        res = sum;
        for(int i = k;i<nums.size();i++) {
            sum += (long long)(nums[i]-nums[i-k]);
            if(sum > res)
                res = sum;
        }
        return (double)(res)/(double)(k);
    }
};