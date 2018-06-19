class Solution {
public:
    int dim;
    vector<vector<string>> res;
    vector<int> oneans;
    
public:
    vector<vector<string>> solveNQueens(int n) {
        dim = n;
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
            res.push_back(convert_to_ans());
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
    
    vector<string> convert_to_ans()
    {
        vector<string> res;
        for(int i = 0;i<dim;i++)
        {
            string temp(dim,'.');
            temp[oneans[i]] = 'Q';
            res.push_back(temp);
        }
        return res;
    }
};