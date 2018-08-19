class Solution {

vector<int> takeup;
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        for(int i = 0;i<bank.size();i++)
            takeup.push_back(0);
        takeup.push_back(1);
        
        bank.push_back(start);
        vector<int> temp;
        vector<vector<int>> figure(bank.size(), temp);
        int from = -1;
        int to = -1;
        
        for(int i = 0;i<bank.size();i++)
        {
            if(bank[i] == start)
                from = i;
            if(bank[i] == end)
                to = i;
            for(int j = i+1;j<bank.size();j++)
            {
                if(test(bank[i],bank[j]) == 1)
                {
                    figure[i].push_back(j);
                    figure[j].push_back(i);
                }
            }
        }
        if(to == -1)
            return -1;
        
        return travel(figure, from, to);
    }
    
    bool test(string& A, string& B)
    {
        if(A.size() != B.size())
            return false;
        int time = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] != B[i])
                time++;
        }
        if(time == 1)
            return true;
        else
            return false;
    }
    
    int travel(vector<vector<int>>& figure, int from, int to)
    {
        if(from == to)
            return 0;
        int min = INT_MAX;
        for(int i = 0;i<figure[from].size();i++)
        {
            if(takeup[figure[from][i]] == 0)
            {
                takeup[figure[from][i]] = 1;
                int res = travel(figure, figure[from][i], to);
                if(res != -1)
                {
                    if(res+1 < min)
                        min = res+1;
                }
                takeup[figure[from][i]] = 0;
            } 
        }
        if(min == INT_MAX)
            return -1;
        return min;
    }
};