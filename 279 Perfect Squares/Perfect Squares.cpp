class Solution {
private:
    bool isSquare(int n)
    {
        int base = sqrt(n);
        if(n == base*base)
            return true;
        return false;
    }
    
public:
    int numSquares(int n) {
        if(isSquare(n))
            return 1;
        deque<vector<int>> dq;
        vector<int> temp(3,0);
        vector<int> node(3,0);
        for(int i = sqrt(n);i>=1;i--)
        {
            temp[0] = i*i;
            temp[1] = i;
            temp[2] = 1;
            dq.push_back(temp);
        }
        
        while(1)
        {
            node = dq.front();
            dq.pop_front();
            int i = sqrt(n-node[0]);
            if(i > node[1])
                i = node[1];
            for(;i>=1;i--)
            {
                temp[0] = node[0]+i*i;
                temp[1] = i;
                temp[2] = node[2]+1;
                if(temp[0] == n)
                    return temp[2];
                else
                    dq.push_back(temp);
            }
        }
    }
};