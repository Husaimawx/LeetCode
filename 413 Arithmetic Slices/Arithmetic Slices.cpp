class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        
        int res = 0;
        int from = 0;
        
        while(1) {
            if(from + 2 >= A.size())
                return res;
            int dis = A[from+1]-A[from];
            int to;
            for(to = from+2;to < A.size();to++)
                if(A[to]-A[to-1] != dis)
                    break;
            
            if(to != from+2)
                res += (to-from-1)*(to-from-2)/2;
            
            from = to-1;
        }
    }
};
