class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        
        int from = 0;
        for(;from+1 < A.size();from++) {
            if(A[from] < A[from+1])
                break;
        }
        if(from == A.size()-1)
            return 0;

        int res = 0;
        while(1) {
            int i;
            for(i = from+1;i<A.size();i++) {
                if(A[i] <= A[i-1])
                    break;
            }    
            
            if(i == A.size())
                return res;
            if(A[i] == A[i-1]) {
                from = i;
                continue;
            }
            if(i == from+1) {
                from = i;
                continue;
            }

            while(i<A.size()) {
                if(A[i] >= A[i-1]) {
                    res = max(res, i-from);
                    from = i-1;
                    break;
                }
                i++;
            }
            if(i == A.size()) {
                return max(res, int(A.size())-from);
            }
        }
        return res;
    }
};