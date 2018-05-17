// Brute Force
class Solution {
public:
    int ans;
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.size() == 0)
            return 0;
        ans = 0;    
        DFS(nums, 0, S);
        return ans;
    }
    
    void DFS(vector<int>& nums, int from, int S)
    {
        if(from == nums.size()-1)
        {
            if(nums[from] == S)
                ans++;
            if(nums[from] == -S)
                ans++;
            return;
        }
        DFS(nums, from+1, S+nums[from]);
        DFS(nums, from+1, S-nums[from]);
    }
};

// Dynamic Programming
class Solution {
public:
    int ans;
    
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S<0)
            S*=-1;
        if(S > 1000)
            return 0;
        vector<int> temp(1501,0);
        vector<vector<int>> res(2, temp);
        res[0][500] = 1;
        int pos = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            for(int j = 0;j<=1500;j++)
            {
                res[1-pos][j] = 0;
                if(j+nums[i]<=1500)
                    res[1-pos][j] += res[pos][j+nums[i]];
                if(j-nums[i]>=0)
                    res[1-pos][j] += res[pos][j-nums[i]];
            }
            pos = 1-pos;
        }
        
        int j = S+500;
        int i = nums.size()-1;
        int ans = 0;
        if(j+nums[i]<=1500)
            ans += res[pos][j+nums[i]];
        if(j-nums[i]>=0)
            ans += res[pos][j-nums[i]];
        
        return ans;
    }
};