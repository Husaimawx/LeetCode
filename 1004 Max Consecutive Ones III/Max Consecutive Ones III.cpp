class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int from = 0;
        int to = 0;
        int num = 0;
        int res = 0;
        while(1) {
            if(num > K) {
                if(A[from] == 0)
                    num -= 1;
                from += 1;
                continue;
            }
            res = max(to-from, res);
            if(to == A.size())
                return res;
            if(A[to] == 0)
                num += 1;
            to += 1;
        }
    }
};