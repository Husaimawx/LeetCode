class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        if(n < 3)
            return n;
        vector<int> res(n+1,0);
        res[0] = 1;
        res[1] = 1;
        res[2] = 2;
        for(int i = 3;i<=n;i++)
        {
            for(int j = 0; j<=i-1; j++)
            {
                res[i] += res[j]*res[i-1-j];
            }
        }
        return res[n];
    }
};