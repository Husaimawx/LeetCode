class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {

        vector<int> B(A.size(),A.size());
        int from = 0;
        int to = 0;
        unordered_map<int,int> M;
        M[A[0]] = 1;
        while(from != A.size()) {
            while(M.size() < K) {
                to += 1;
                //if(M.count(A[to]) == 0) {
                //    M[A[to]] = 1;
                //} else {
                if(to == A.size())
                    break;
                M[A[to]] += 1;
                //}
            }
            if(to == A.size())
                break;
            B[from] = to;
            M[A[from]] -= 1;
            if(M[A[from]] == 0) {
                M.erase(A[from]);
            }
            from+=1;
        }
        
        K+=1;
        vector<int> C(A.size(),A.size());
        from = 0;
        to = 0;
        unordered_map<int,int> M2;
        M2[A[0]] = 1;
        while(from != A.size()) {
            while(M2.size() < K) {
                to += 1;
                //if(M.count(A[to]) == 0) {
                //    M[A[to]] = 1;
                //} else {
                if(to == A.size())
                    break;
                M2[A[to]] += 1;
                //}
            }
            if(to == A.size())
                break;
            C[from] = to;
            M2[A[from]] -= 1;
            if(M2[A[from]] == 0) {
                M2.erase(A[from]);
            }
            from+=1;
        }
        
        int res = 0;
        //for(int i = 0;i<A.size();i++) {
        //    cout << B[i];
        //}
        //cout << endl;
        //for(int i = 0;i<A.size();i++) {
        //    cout << C[i];
        //}
        for(int i = 0;i<A.size();i++) {
            res += (C[i] -B[i]);
        }
        return res;
    }
};