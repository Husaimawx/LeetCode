class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double>> res(K,vector<double>(A.size(),0));
        int sum = 0;
        for(int i = 0;i<A.size();i++)
        {
            sum += A[i];
            res[0][i] = (double)(sum) / (double)(i+1);
        }
        
        for(int i = 1;i<K;i++)
        {
            for(int j = i; j<A.size();j++)
            {
                res[i][j] = 0;
                sum = 0;
                for(int t = j;t>=i;t--)
                {
                    sum += A[t];
                    res[i][j] = max(res[i][j],(double)(sum)/(double)(j-t+1)+res[i-1][t-1]);
                }
            }
        }
        return res[K-1][A.size()-1];
    }
};