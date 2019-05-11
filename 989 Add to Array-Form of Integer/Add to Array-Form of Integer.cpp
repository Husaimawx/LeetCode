class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K == 0)
            return A;
        vector<int> temp(5,0);
        A.insert(A.begin(), temp.begin(),temp.end());
        vector<int> B;
        while(K != 0) {
            B.push_back(K%10);
            K = K/10;
        }
        
        int f1 = A.size()-1;
        for(int i = 0;i<B.size();i++) {
            A[f1] += B[i];
            if(A[f1] > 9) {
                A[f1] -= 10;
                A[f1-1] += 1;
            }
            f1 -= 1;
        }
        while(A[f1] > 9) {
            A[f1] -= 10;
            A[f1-1] += 1;
            f1 -= 1;
        }
        for(int i = 0;i<A.size();i++) {
            if(A[i] != 0) {
                vector<int> res(A.begin()+i,A.end());
                return res;
            }
        }
        return A;
    }
};