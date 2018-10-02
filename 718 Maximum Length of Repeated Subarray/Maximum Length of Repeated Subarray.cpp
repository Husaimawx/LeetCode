// Brute Force
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int res = 0;
        for(int i = 0;i<A.size();i++)
        {
            if(res+i >= A.size())
                break;
            for(int j = 0;j<B.size();j++)
            {
                if(res+i >= A.size() || res+j >= B.size())
                    break;
                int t = 0;
                while(i+t != A.size() && t+j != B.size() && A[i+t] == B[t+j])
                    t++;
                if(res < t)
                    res = t;
            }
        }
        return res;
    }
};

// DP
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int mx = 0;
        vector<vector<int>> res(A.size(),vector<int>(B.size(),0));
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == B[0])
            {
                res[i][0] = 1;
                mx = 1;
            }
            else
                res[i][0] = 0;
        }
        for(int i = 0;i<B.size();i++)
        {
            if(A[0] == B[i])
            {
                res[0][i] = 1;
                mx = 1;
            }
            else
                res[0][i] = 0;
        }
        for(int i = 1;i<A.size();i++)
        {
            for(int j = 1;j<B.size();j++)
            {
                if(A[i] == B[j])
                {
                    res[i][j] = res[i-1][j-1]+1;
                    if(mx < res[i][j])
                        mx = res[i][j];
                }
                else
                    res[i][j] = 0;
            }
        }
        return mx;
    }
};