class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;
        
        int from = 0;
        while(from < nums.size()) {
            int i;
            for(i = from;i+1<nums.size();i++) {
                if(nums[i]+1 != nums[i+1])
                    break;
            }
            string temp;
            if(from != i)
                temp = to_string(nums[from])+"->"+to_string(nums[i]);
            else
                temp = to_string(nums[from]);
            res.push_back(temp);
            from = i+1;
        }
        return res;
    }
};