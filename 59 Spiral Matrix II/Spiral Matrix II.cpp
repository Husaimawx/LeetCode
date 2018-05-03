class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n,0);
        vector<vector<int>> res(n, temp);
        int order = 0;
        int xnow = 0;
        int ynow = -1;
        for(int i = 1; i<=n*n; i++)
        {
            switch(order)
            {
                case 0:
                    ynow++;
                    res[xnow][ynow] = i;
                    if((ynow+1) == n || res[xnow][ynow+1] != 0)
                    {
                        order = 1;
                    }
                    break;
                case 1:
                    xnow++;
                    res[xnow][ynow] = i;
                    if((xnow+1) == n || res[xnow+1][ynow] != 0)
                    {
                        order = 2;
                    }
                    break;
                case 2:
                    ynow--;
                    res[xnow][ynow] = i;
                    if((ynow-1) == -1 || res[xnow][ynow-1] != 0)
                    {
                        order = 3;
                    }
                    break;
                case 3:
                    xnow--;
                    res[xnow][ynow] = i;
                    if((xnow-1) == -1 || res[xnow-1][ynow] != 0)
                    {
                        order = 0;
                    }
                    break;
            }
        }
        return res;
    }
};