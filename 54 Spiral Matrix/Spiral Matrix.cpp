class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m == 0)
            return res;
        int n = matrix[0].size();
        if(n == 0)
            return res;
        
        int fromx = 0, fromy = 0, tox = n-1, toy = m-1;
        int direct = 0;
        int i;
        while(fromx <= tox && fromy <= toy)
        {
            if(direct == 0)
            {
                for(i = fromx; i<=tox;i++)
                    res.push_back(matrix[fromy][i]);
                fromy++;
                direct = 1;
            }
            else if(direct == 1)
            {
                for(i = fromy;i<=toy;i++)
                    res.push_back(matrix[i][tox]);
                tox--;
                direct = 2;
            }
            else if(direct == 2)
            {
                for(i = tox;i>=fromx;i--)
                    res.push_back(matrix[toy][i]);
                toy--;
                direct = 3;
            }
            else
            {
                for(i = toy;i>=fromy;i--)
                    res.push_back(matrix[i][fromx]);
                fromx++;
                direct = 0;
            }
        }
        
        return res;
    }
};