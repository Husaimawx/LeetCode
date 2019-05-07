class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<int> old;
        vector<int> nw;
        int count = 0;
        unordered_map<int,int> M;
        for(int i = 0;i<A.size();i++) {
            if(M.count(A[i]) == 0)
                M[A[i]] = 1;
            else {
                old.push_back(A[i]);
                count += 1;
            }
            int dis;
            if(i+1 == A.size())
                dis = INT_MAX;
            else {
                dis = A[i+1]-A[i];
            }
            for(int j = 1;j<dis;j++) {
                if(count == 0)
                    break;
                else {
                    count -= 1;
                    nw.push_back(A[i]+j);
                }
            }
        }
        int res = 0;
        for(int i = 0;i<old.size();i++)
            res += (nw[i]-old[i]);
        return res;
    }
};