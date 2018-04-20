class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        combinationSum2temp(candidates, target, res, combination, candidates.size()-1);
        return res;
    }

private:
    void combinationSum2temp(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int to)
    {
        if(target == 0)
        {
            res.push_back(combination);
            return;
        }
        else
        {
            if(to < 0)
                return;
            int times = 0;
            for(int i = to;i>=0,candidates[i] == candidates[to];i--)
                times++;
            if(candidates[to] > target)
            {
                combinationSum2temp(candidates,target,res,combination,to-times);
                return;
            }
            for(int j = 0;j<=times;j++)
            {
                combinationSum2temp(candidates, target-candidates[to]*j, res, combination, to-times);
                combination.push_back(candidates[to]);
            }
            for(int j = 0;j<=times;j++)
                combination.pop_back();
            return;
        }
    }
};