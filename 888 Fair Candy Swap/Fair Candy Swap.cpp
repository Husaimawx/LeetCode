class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum = 0;
        
        for(int i = 0;i<A.size();i++)
            sum += A[i];
        for(int i = 0;i<B.size();i++)
            sum -= B[i];
        
        sum = sum/2;
        
        map<int,int> M;
        
        for(int i = 0;i<A.size();i++)
            M[A[i]] = 1;
        for(int i = 0;i<B.size();i++) {
            if(M.count(B[i]+sum) != 0) {
                vector<int> res(2, B[i]);
                res[0] += sum;
                return res;
            }
        }
        
        vector<int> res;
        return res;
    }
};