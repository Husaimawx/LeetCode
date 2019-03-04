class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /*
        if(nums.size() < 2)
            return nums.size();
        vector<int> line(1,nums[0]);
        
        for(int i = 1;i<nums.size();i++) {
            int from = 0;
            int to = line.size();
            if(nums[i] >= line[line.size()-1])
                line.push_back(nums[i]);
            else {
                while(from != to) {
                    int mid = (from+to)/2;
                    if(nums[i] < line[mid])
                        to = mid;
                    else
                        from = mid+1;
                }
                line[from] = nums[i];
            }
        }
        return line.size();
        */
        if(nums.size() < 2)
            return nums.size();
        
        int from = 0;
        int to = 0;
        int res = 1;
        for(int i = 1;i<nums.size();i++) {
            if(nums[i] > nums[i-1])
                to += 1;
            else {
                res = max(res, to-from+1);
                from = i;
                to = i;
            }
        }
        res = max(res, to-from+1);
        return res;
    }
};