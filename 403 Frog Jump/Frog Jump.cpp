class Solution {
unordered_map<int, bool> M;
public:
    bool canCross(vector<int>& stones) {
        if(stones[0]+1 != stones[1])
            return false;
        bool res = canCrossAux(stones,1,1);
        return res;
    }
    
    bool canCrossAux(vector<int>& stones, int pos, int step)
    {
        if(M.count(pos+(step<<11)) != 0)
            return M[pos+(step<<11)];
        if(stones.size() == pos+1)
        {
            M[pos+(step<<11)] = true;
            return true;
        }
        for(int i = pos+1;i<stones.size();i++)
        {
            if(stones[i]-stones[pos]>step+1)
            {
                M[pos+(step<<11)] = false;
                return false;
            }
            else if(stones[i]-stones[pos]==step+1)
            {
                if(canCrossAux(stones, i, step+1))
                {
                    M[pos+(step<<11)] = true;
                    return true;
                }
            }
            else if(stones[i]-stones[pos]==step)
            {
                if(canCrossAux(stones, i, step))
                {
                    M[pos+(step<<11)] = true;
                    return true;           
                }
            }
            else if(stones[i]-stones[pos]==step-1)
            {
                if(canCrossAux(stones, i, step-1))
                {
                    M[pos+(step<<11)] = true;
                    return true;
                }
            }
        }
        M[pos+(step<<11)] = false;
        return false;
    }
};