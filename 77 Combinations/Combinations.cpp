class Solution {
public:
    vector<vector<int>> res;
    vector<int> line;
    int number;
    
public:
    vector<vector<int>> combine(int n, int k) {
        if(k > n || k == 0)
            return res;
        
        number = n;
        
        combineAux(k);
        
        return res;
    }
    
    void combineAux(int k)
    {
        if(k == 0)
        {
            res.push_back(line);
            return;
        }
        int i;
        if(line.size() == 0)
            i = 1;
        else
            i = line[line.size()-1]+1;
        for(;i<=number-k+1;i++)
        {
            line.push_back(i);
            combineAux(k-1);
            line.pop_back();
        }
        return;
    }
};