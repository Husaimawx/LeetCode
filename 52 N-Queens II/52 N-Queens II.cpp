class Solution {
public:
    int dim;
    int res;
    vector<int> oneans;

public:
    int totalNQueens(int n) {
        dim = n;
        res = 0;
        solveNQueensAux(0);
        return res;        
    }
    
    bool check(int n)
    {
        for(int i = 0;i<oneans.size();i++)
        {
            if(oneans[i] == n)
                return false;
            if(abs(n-oneans[i]) == abs(oneans.size()-i))
                return false;
        }
        return true;
    }
    
    void solveNQueensAux(int layer)
    {
        if(layer == dim)
        {
            res++;
            return;
        }
        for(int i = 0;i<dim;i++)
        {
            if(check(i))
            {
                oneans.push_back(i);
                solveNQueensAux(layer+1);
                oneans.pop_back();
            }   
        }
        return;
    }
};