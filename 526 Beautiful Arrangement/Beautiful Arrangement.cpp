class Solution {
public:
    int countArrangement(int N) {
        vector<int> temp;
        vector<vector<int>> devisor(N, temp);
        for(int i = 1;i<=N;i++)
        {
            for(int j = 1;i*j<=N;j++)
            {
                devisor[i*j-1].push_back(i);
                if(j != 1)
                    devisor[i-1].push_back(i*j);
            }
        }
        
        vector<int> takeup(N,0);
        int res = countArrangementAux(devisor, takeup, N, N);
        return res;
    }
    
    int countArrangementAux(vector<vector<int>>& devisor, vector<int>& takeup, int N, int start)
    {
        if(start == 0)
            return 1;
        int res = 0;
        for(int i = 0;i<devisor[start-1].size();i++)
        {
            int num = devisor[start-1][i]-1;
            if(takeup[num] == 0)
            {
                takeup[num] = 1;
                res += countArrangementAux(devisor, takeup, N, start-1);
                takeup[num] = 0;
            }
        }
        return res;
    }
};