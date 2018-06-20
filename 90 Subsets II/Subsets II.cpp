class Solution {
public:
    vector<vector<int>> res;
    vector<pair<int,int>> line;
    vector<pair<int,int>> input;
    int n;
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() == 0)
            return res;
        
        input.push_back(pair<int,int>(1,nums[0]));
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == nums[i-1])
                input[input.size()-1].first++;
            else
                input.push_back(pair<int,int>(1,nums[i]));
        }
        
        n = input.size();
        
        subsetsWithDupAux(0);
        
        return res;
    }
    
    void subsetsWithDupAux(int start)
    {
        if(start == n)
        {
            vector<int> temp;
            for(int i = 0;i<line.size();i++)
            {
                for(int j = 0;j<line[i].first;j++)
                {
                    temp.push_back(line[i].second);        
                }
            }
            res.push_back(temp);
            return;
        }
        
        line.push_back(pair<int,int>(0,input[start].second));
        for(int i = 0;i<=input[start].first;i++)
        {
            subsetsWithDupAux(start+1);
            line[line.size()-1].first++;
        }
        line.pop_back();
        return;
    }
};