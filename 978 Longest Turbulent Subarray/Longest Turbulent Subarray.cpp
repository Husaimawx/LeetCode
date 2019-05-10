class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int base = 1;
        if(A.size()<2)
            return A.size();
        for(int i = 0;i+1<A.size();i++) {
            A[i] -= A[i+1];
            if(A[i] != 0) {
                A[i] = (A[i] > 0 ? 1 : -1);
                base = 2;
            }
        }
        A.resize(A.size()-1);
        for(int i = 0;i+1<A.size();i++) {
            A[i] *= A[i+1];
        }
        A.resize(A.size()-1);
        //for(int i = 0;i<A.size();i++) {
        //    cout << A[i] << ' ';
        //}
        int res = 0;
        int temp = 0;
        
        for(int i = 0;i<A.size();i++) {
            if(A[i] < 0)
                temp += 1;
            else
                temp = 0;
            res = max(res,temp);
        }
        return res+base;
    }
};