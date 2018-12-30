class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;

        int maxnum = nums[0];
        int minnum = nums[0];
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] > maxnum)
                maxnum = nums[i];
            if(nums[i] < minnum)
                minnum = nums[i];
        }
        if(minnum == maxnum)
            return 0;
        int bucket_size = (maxnum-minnum)/(nums.size()-1);
        if(bucket_size == 0)
            bucket_size = 1;
        int m = (maxnum - minnum) / bucket_size + 1;
        vector<int> minBucket(m,INT_MAX);
        vector<int> maxBucket(m,INT_MIN);
        for(int i = 0;i<nums.size();i++) {
            int bk = (nums[i]-minnum)/bucket_size;
            if(minBucket[bk] > nums[i])
                minBucket[bk] = nums[i];
            if(maxBucket[bk] < nums[i])
                maxBucket[bk] = nums[i];
        }
        vector<int> special;
        for(int i = 0;i<minBucket.size();i++) {
            if(minBucket[i] == INT_MAX)
                continue;
            special.push_back(minBucket[i]);
            special.push_back(maxBucket[i]);
        }
        int res = 0;
        for(int i = 1;i+1<special.size();i+=2) {
            res = max(res,special[i+1]-special[i]);
        }
        return res;
    }
};