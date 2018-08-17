class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> M;
        
        int flag = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(M.count(nums[i]))
                M[nums[i]] += 1;
            else
                M[nums[i]] = 1;
        }
        
        map<int,vector<int>> reverse_M;
        for(auto iter = M.begin();iter != M.end();iter++)
        {
            if(!reverse_M.count(iter->second))
            {
                vector<int> temp(1,iter->first);
                reverse_M[iter->second] = temp;
            }
            else
                reverse_M[iter->second].push_back(iter->first);
        }
        
        vector<int> res;
        for(auto iter = reverse_M.rbegin();iter != reverse_M.rend();iter++)
        {
            for(int i = 0;i<(iter->second).size();i++)
            {
                res.push_back(iter->second[i]);
                k--;
                if(k == 0)
                    return res;
            }
        }
        return res;
    }
};