class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if(A.size() == 1)
            return 1;
        unordered_map<int,int> prev;
        prev[A[0]] = 1;
        unordered_map<int,int> M;
        M[A[0]] = 1;
        for(int i = 1;i<A.size();i++) {
            unordered_map<int,int> prev_temp;
            prev_temp[A[i]] = 1;
            if(M.count(A[i]) == 0)
                M[A[i]] = 1;
            for(auto iter = prev.begin();iter != prev.end();iter++) {
                int temp = (iter->first) | A[i];
                if(M.count(temp) == 0) {
                    M[temp] = 1;
                }
                prev_temp[temp] = 1;
            }
            prev = prev_temp;
        }
        return M.size();
    }
};