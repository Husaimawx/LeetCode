class Solution {
vector<vector<int>> res;
int N;
int K;
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        N = n;
        K = k;
        vector<int> now;
        combinationSum3Aux(now, 0);
        return res;
    }
    
    void combinationSum3Aux(vector<int>& now, int sum)
    {
        if(now.size() == K-2)
        {
            int from = 1;
            if(now.size() != 0)
                from = now[now.size()-1]+1;
            for(int i = from;i<=(N-sum-1)/2 && i<10;i++)
            {
                if(N-sum-i >= 10)
                    continue;
                now.push_back(i);
                now.push_back(N-sum-i);
                res.push_back(now);
                now.pop_back();
                now.pop_back();
            }
            return;
        }
        int from = 1;
        if(now.size() != 0)
            from = now[now.size()-1]+1;
	    for (int i = from; i <= ((N - sum) / (K - int(now.size())) - (K - int(now.size())) / 2 + 1) && i < 10; i++)
        {
            now.push_back(i);
            combinationSum3Aux(now, sum+i);
            now.pop_back();
        }    
    }
};