class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> lastres;
        int len = nums.size();
        if(len == 0 || len == 1)
        {
            res.push_back(nums);
            return res;
        }
        
        vector<int> copy;
        for(int i = 0;i< len;i++)
        {
            int chooseNum = nums[i];
            copy = nums;
            copy[i] = copy[len-1];
            copy.pop_back();
            lastres = permute(copy);
            for(auto iter = lastres.begin();iter<lastres.end();iter++)
            {
                (*iter).push_back(chooseNum);
                res.push_back((*iter));
            }
        }
        return res;
    }
};