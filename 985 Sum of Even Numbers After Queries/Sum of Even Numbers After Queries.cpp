class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int base = 0;
        for(int i = 0;i<A.size();i++) {
            if(A[i] % 2 == 0)
                base += A[i];
        }
        for(int i = 0;i<queries.size();i++) {
            A[queries[i][1]] += queries[i][0];
            if(queries[i][0] % 2 == 0) {
                if(A[queries[i][1]] % 2 == 0)
                    base += queries[i][0];
            } else {
                if(A[queries[i][1]] % 2 == 0)
                    base += A[queries[i][1]];
                else
                    base -= (A[queries[i][1]] - queries[i][0]);
            }
            res.push_back(base);
        }
        return res;
    }
};