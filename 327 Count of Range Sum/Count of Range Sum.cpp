class Solution {
public:
    int mergeSort(vector<long>& nums, int lower, int upper, int from, int to) {
        if(from >= to)
            return 0;

        int mid = (from+to)/2;
        int res1 = mergeSort(nums, lower, upper, from, mid);
        int res2 = mergeSort(nums, lower, upper, mid+1, to);
        int res = res1+res2;
        
        int i = from;
        int j = mid+1;
        int k = mid+1;
        for(;i<=mid;i++) {
            while(j<=to && nums[j]<=nums[i]+upper) j++;
            while(k<=to && nums[k]<nums[i]+lower) k++;
            res += j-k;
        }
        
        inplace_merge(nums.begin()+from, nums.begin()+mid+1,nums.begin()+to+1);
        return res;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.size() < 1)
            return 0;
        
        vector<long> data(1,0);
        for(int i = 0;i<nums.size();i++) {
            data.push_back(data[data.size()-1]+nums[i]);
        }
        
        int res = mergeSort(data, lower, upper, 0, data.size()-1);
        return res;
    }
};